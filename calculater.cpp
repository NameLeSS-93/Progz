#include <iostream>
#include <string>
using namespace std;

bool par_err = false;
//bool fac_err = false;
double expression();
double term();
double primary();
int fact(int n);
void error(string s);

class Token
{
  public:
	char kind;
	double value;
	Token(char ch)
		: kind(ch), value(0) {}
	Token(char ch, double val)
		: kind(ch), value(val) {}
};

class Token_stream
{
  public:
	Token_stream();
	Token get();
	void putback(Token t);

  private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream()
	: full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full)
		error("Buffer is full!");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case ';':
	case 'q':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '{':
	case '}':
	case '!':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	}
	default:
		error("Wrong lexem!");
	}
}

Token_stream ts;

double left_exp;

double expression()
{
	left_exp = term();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left_exp += term();
			t = ts.get();
			break;
		case '-':
			left_exp -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left_exp;
		}
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("Division by zero!");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}
double d, b;

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		/*double*/ d = expression();
		t = ts.get();
		if (t.kind == '{')
		{
			/*double*/ b = expression();
			t = ts.get();
			if (t.kind != '}')
			{
				par_err = true;
				error("'}' expected");
			}
			return b; // test changing value b and d
		}
		if (t.kind != ')')
		{
			par_err = true;
			error("')' expected");
		}
		return d;
	}
	case '{':
	{
		/*double*/ d = expression();
		t = ts.get();
		if (t.kind == '(')
		{
			/*double*/ b = expression();
			t = ts.get();
			if (t.kind != ')')
			{
				par_err = true;
				error("')' expected");
			}
			return b;
		}
		if (t.kind != '}')
		{
			par_err = true;
			error("'}' expected");
		}
		return d;
	}
	case '8':
	{
		double num = t.value;
		t = ts.get();
		if (t.kind == '!')
		{
			return fact(int(num));
		}
		ts.putback(t);
		return num;
	}
	default:
		error("primary expected");
	}
}

int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);
}

void error(string s)
{ // функция выводящее сообщение об ошибке
	cout << s << endl;
}

int main()
{
	cout << "This is Calculator ver 1.7. Your can use '+', '-', '*', '/', '!', '(', ')', '{', '}'\n"
		 << "Enter expression to execute: ";
	double val = 0;
	while (cin)
	{
		Token t = ts.get();
		if (t.kind == 'q')
			break;
		if (par_err)
		{
			par_err = false;
			continue;
		}
		if (t.kind == ';')
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
	return 0;
}
