#include<iostream>

using namespace std;

int main(){
  long long a, b;
  while(cin >> a >> b){
    if(a == 0 && b == 0){
      break;
    }
    int carry = 0;
    int sum = 0;
    while(a > 0 || b > 0){
      if((a % 10) + (b % 10) + sum >= 10){
        sum = 1;
        carry++;
      }else{
        sum = 0;
      }
      a /= 10;
      b /= 10;
    }
    if(carry == 0){
      cout << "No carry operation." << endl;
    }else if(carry == 1){
      cout << "1 carry operation." << endl;
    }else{
      cout << carry << " carry operations." << endl;
    }
  }
  return 0;
}
