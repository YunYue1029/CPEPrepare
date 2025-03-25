#include<iostream>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

int main(){
  int N;
  while(cin >> N){
    vector<int> number(N ,0);
    for(int i = 0; i < N ; i++){
      cin >> number[i];
    }
    set<int> diff;
    for(int i = 1; i < N; i++){
      int D = abs(number[i] - number[i -1]);
      if(D > 0 && D < N){
        diff.insert(D);
      }
    }
    if(diff.size() == N -1){
      cout << "Jolly" << endl;
    }else{
      cout << "Not jolly" << endl;
    }
  }
  return 0;
}
