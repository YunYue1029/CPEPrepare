#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
  int N;
  int count = 1;
  while(cin >> N){
    bool check = true;
    vector<int> number(N);
    for(int i = 0; i < N; i++){
      cin >> number[i];
    }
    set<int> SetC;
    for(int i = 0; i < N - 1; i++){
      for(int j = i + 1; j < N; j++){
        int sum = number[i] + number[j];
        if(SetC.count(sum)){
          check = false;
        }else{
          SetC.insert(sum);
        }
      }
    }
    cout << "Case #";
    if(check){
      cout << count << ": It is a B2-Sequence." << endl;
    }else{
      cout << count << ": It is not a B2-Sequence." << endl;
    }
    count++;
  }
  return 0;
}
