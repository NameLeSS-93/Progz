#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Name_value {
public:
    string name;
    double value;
    Name_value(string nm, double num)
    :name(nm), value(num) {}
};

int main(){
    vector<Name_value>Name;
    string name;
    double num;
    while(cin >> name >> num){
        if(name == "NoName" && num == 0){
            break;
        } else {
            Name.push_back(Name_value(name, num));
            for(int i = 0; i != Name.size()-1; i++){
                if(name == Name[i].name && Name.size() != 1) {
                    cout << "You have already entered this name\n";
                    Name.erase(Name.end());
                    //Name.erase(Name.begin()+i+1);
                    continue;
                }
            }
        }
    }
    for(int i = 0; i != Name.size(); i++)
    cout << Name[i].name << "\t" << Name[i].value << endl;
    return 0;
}