#include "stddef.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char get_word();
string sen;
vector<char>words;
vector<bool>words_bool;

void error(string s)
{
    cout << s << endl;
}

//bool noun_ind = false;
//bool verb_ind = false;

char get_word()
{
    cin >> sen;
    //cout << sen << endl;
    if(sen == "and" || sen == "or" || sen == "but")
    {
        return 'c';
        //continue;
    } else if(sen == "birds" || sen == "fish" || sen == "C++")
    {
        return 'n';
        //continue;
    }else if(sen == "rules" || sen == "fly" || sen == "swim")
    {
        return 'v';
        // continue;
    }else if(sen == ".") 
    {
        return '.';
        //break;
    }else if(sen == "exit") 
    {
        return 'e';
        //break;
    } else error("wrong lexem"); 
}

void sentence()
{
    char ch = get_word();
    switch(ch)
    {
        case 'n': case 'v': case 'c': case '.': case 'e':
        {
        words.push_back(ch);
        sentence();
        break;
        }
        default:
        { 
            error("Wrong lexem(s)");
            break;
        }
    }
    
}

bool gram_an(vector<char>vec)
{
    vector<bool>words_bool(words.size(), false);
    for(int i = 0, iter = 0; i != vec.size(); i++)
    {
        if((i == 0 || i == iter) && words[i] == 'n')
        {
            iter++;
            words_bool[i] = true;
            continue;
        } else if((i == 1 || i == iter) && words[i] == 'v')
        {
            iter++;
            words_bool[i] = true;
            continue;
        } else if((i == 2 || i == iter) && words[i] == 'c')
        {
            iter++;
            words_bool[i] = true;
            continue;
        }else if((i == vec.size() - 1) && words[i] == '.')
        {
            iter++;
            words_bool[vec.size() - 1] = true;
            continue;
        }
    }
    for(int i = 0; i != words_bool.size(); i++)
    {
        int sen_check = 0;
        if(words[i] == true)
        {
            sen_check++;
            if(sen_check == words_bool.size()) return true;
        } 
        else return false;
    }
}
int main() 
{
    while(1)
    {   
        sentence();
        bool bSen = gram_an(words);
        if(words[0] == 'e') break;
        if(bSen)
        {
            cout << "This is a sentence\n";
            words.clear(); 
        } else
        {
            cout << "This is NOT a sentence\n";
            words.clear();
        }
    }
    return 0;
}