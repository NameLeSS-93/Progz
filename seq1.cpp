#include<iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]) {
  while(1){
  long double a0;
  cin >> a0;
  for(int i = 0; i < 1000000; i++)
  {
    a0 = 1.2 * sin(a0);
  }
  std::cout << "result: " << a0 << " " << M_PI/2 << /*(1 + sqrt(5))/2*/ '\n';
}
  return 0;
}
