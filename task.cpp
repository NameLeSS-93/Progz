#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> get_word();
string sen;
vector<string>words;

void error(string s)
{
    cout << s << endl;
}

bool noun_ind = false;
bool verb_ind = false;

vector<string> get_word()
{
   
        cin >> sen;
        cout << sen << endl;
        if(sen == "and" || sen == "or" || sen == "but")
        {
            words.push_back("conj");
            continue;
        } else if(sen == "birds" || sen == "fish" || sen == "C++")
        {
            words.push_back("noun");
            continue;
        }else if(sen == "rules" || sen == "fly" || sen == "swim")
        {
            words.push_back("verb");
            continue;
        }else if(sen == ".") 
        {
            words.push_back(".");
            //break;
        }else if(sen == "exit") 
        {
            words.push_back("exit");
            //break;
        } else error("wrong lexem"); 
    
    return words;
}

bool sentence(vector<string>words)
{
    for(int i = 0; i != words.size(); i++)
    {
        if((i == 0 || i == 3) && words[i] == "noun"){
            noun_ind = true;
            continue;
        } else if((i == 1 || i == 4) && words[i] == "verb"){
            verb_ind = true;
            continue;
        } else if(i == 2 && words[i] == "conj")
        {
            noun_ind = false;
            verb_ind = false;
            continue;
        }
    } 
    if((noun_ind && verb_ind) && words[words.size()-1] == ".")
    {
        return true;
    } else return false;
}

int main() 
{

    while(1)
    {
        bool ind = sentence(get_word());
        //words.push_back(get());
        if(words[0] == "exit") break;
        if(ind)
        {
            noun_ind = false;
            verb_ind = false;
            cout << "This is a sentence\n";
            words.clear();
        } 
        else
        {
            noun_ind = false;
            verb_ind = false;
            cout << "This is not a sentence\n";
            words.clear();
        }
    }
    return 0;
}