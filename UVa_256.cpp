#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

bool isQuisksome(int number, int d){
  int div = pow(10, d/2);
  int A = number / div;
  int B = number % div;
  return (A+B) * (A+B) == number;
}

void findQuirksomeNumber(int d){
  int limit = pow(10, d);
  for(int i = 0; i < limit; i++){
    if(isQuisksome(i,d)){
      cout<<setw(d)<<setfill('0')<<i<<endl;
    }
  }
}

int main(){
  int d;
  while(cin>>d){
    findQuirksomeNumber(d);
  }
  return 0;
}

