#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  while(1)
  {
    double a, b, c;
    double a_prev, b_prev, c_prev;
    int iter = 30;
    cin >> a >> b >> c;
    for(int i = 0; i < iter; i++)
    {
      a_prev = a;
      b_prev = b;
      c_prev = c;
      a = (a_prev + b_prev) / 2;
      b = (b_prev + c_prev) / 2;
      c = (a_prev + c_prev) / 2;
    }
    std::cout << a << " " << b << " " << c << '\n';
  }
  return 0;
}
