#include<iostream>

using namespace std;

int main(){
  int S, D;
  while(cin >> S >> D){
    int sum = S;
    while(sum < D){
      S++;
      sum += S;
    }
    cout << S << endl;
  }
  return 0;
}
