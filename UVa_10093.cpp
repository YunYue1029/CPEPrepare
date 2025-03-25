#include<iostream>
#include<string>

using namespace std;

int changeTo(char c){
  if(isdigit(c)) return c - '0';
  if(isupper(c)) return c - 'A' + 10;
  if(islower(c)) return c - 'a' + 36;
  return -1;
}

int main(){
  string R;
  while(cin >> R){
    int maxV = 0;
    int sumV = 0;
    for(char r : R){
      int val = changeTo(r);
      maxV = max(maxV, val);
      sumV += val;
    }
    bool found = false;
    for(int i = maxV +1; i < 62; i++){
      if(sumV % (i - 1) == 0){
        cout << i << endl;
        found = true;
        break;
      }
    }
    if(!found){
      cout << "such number is impossible!" << endl;
    }
  }
  return 0;
}
