#include<iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int day, p;
    cin >> day >> p;
    vector<bool> hartal(day+1, false);
    while(p--){
      int number;
      cin >> number;
      for(int i = number; i <= day; i += number){
        hartal[i] = true;
      }
    }

    int countDay = 0;
    for(int i = 1; i <= day; i++){
      if(i % 7 == 6 || i % 7 == 0){
        continue;
      }else if(hartal[i]){
        countDay++;
      }
    }
    cout << countDay << endl;
  }
  return 0;
}
