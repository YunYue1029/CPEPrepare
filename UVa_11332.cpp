#include<iostream>

using namespace std;

int sumN(int n){
  int sum = 0;
  while(n > 0){
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main(){
  int n;
  while(cin >> n, n != 0){
    while(n > 10){
      n = sumN(n);
    }
    cout << n << endl;
  }
  return 0;
}
