#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
  int char_num = 0;
  int bull_count = 0;
  int cow_count = 0;
  int diff = 0;
  srand(time(0));
  vector<char>symb_ai;
  vector<char>symb_pl;
  vector<bool>repeat(4, 0);
  for(int i = 0; i < 4; i++)
  {
    char_num = rand() % 10 + 97;
    symb_ai.push_back(char(char_num));
  }
  for(int i = 0; i < 4; i++) cout << symb_ai[i] << " ";
  cout << "Please enter 4 letters from 'a' to 'j': ";
  for(int i = 0; i < 4; i++)
  {
    char temp_char;
    cin >> temp_char;
    symb_pl.push_back(temp_char);
  }
  for(int i = 0; i < 4; i++) cout << symb_pl[i] << " ";
  // поиск быков

  for(int i = 0; i < 4; i++)
  {
  if(symb_pl[i] == symb_ai[i]) bull_count++;
  }
  cout << "Number of bulls: " << bull_count;
  vector<char>sorted_vec = symb_ai;
  sort(sorted_vec.begin(), sorted_vec.end());
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      if(symb_pl[i] == symb_pl[j] && i != j) repeat[i] = true;
    }
  }
  for(int i = 0; i < 4; i++)
  {
    cout << "\n" << repeat[i];
  }
  /*for(int i = 0; i != sorted_vec.size(); i++)
  {
    if(i != 0 && sorted_vec[i - 1] == sorted_vec[i]) diff++;
  }*/
  //поиск коров
  if(bull_count != 4)
  {
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        if(symb_ai[i] == symb_pl[j] && i != j) cow_count++;
      }
    }
  } else cout << "You won!" << endl;
  cow_count = cow_count;
  cout << "Number of cows: " << cow_count;
  return 0;
}
