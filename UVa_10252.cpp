#include<iostream>
#include<vector>

using namespace std;

int main(){
  string lineA, lineB;
  while(getline(cin, lineA) && getline(cin, lineB)){
    vector<int> freqA(26, 0), freqB(26, 0);
    for(char c : lineA){
      freqA[c - 'a']++;
    }
    for(char c : lineB){
      freqB[c - 'a']++;
    }
    string result = "";
    for(int i = 0; i < 26; i++){
      int count = min(freqA[i],freqB[i]);
      while(count){
        result += (i + 'a');
        count--;
      }
    }
    cout << result << endl;
  }
  return 0;
}
