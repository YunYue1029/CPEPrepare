#include<iostream>
#include<vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  cin.ignore();
  int count = 0;
  while(N--){
    string ig;
    int t;
    cin >> ig >> ig >> t;
    bool check = true;
    vector<vector<int>> M(t, vector<int>(t));
    for(int i = 0; i < t; i++){
      for(int j = 0; j < t; j++){
        cin >> M[i][j];
        if(M[i][j] < 0){
          check = false;
        }
      }
    }
    for(int i = 0; i < t && check; i++){
      for(int j = 0; j < t; j++){
        if(M[i][j] != M[t - 1 -i][t -1 -j]){
          check = false;
        }
      }
    }
    count++;
    if(check){
      cout << "Test #" << count << ": Symmetric." << endl;
    }else{
      cout << "Test #" << count << ": Non-symmetric." << endl;
    }
  }
  return 0;
}
