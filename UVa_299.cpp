#include<iostream>
#include<vector>

using namespace std;

int bobbleSort(vector<int>& train){
  int swaps = 0;
  int L = train.size();
  for(int i = 0; i < L - 1; i++){
    for(int j = 0; j< L - 1; j++){
      if(train[j] > train[j + 1]){
        swap(train[j] ,train[j + 1]);
        swaps++;
      }
    }
  }
  return swaps;
}
int main(){
  int N;
  cin >> N;
  while(N--){
    int L;
    cin >> L;
    vector<int> train(L);
    for(int i = 0; i < L; i++){
      cin >> train[i];
    }
    int swap = bobbleSort(train);
    cout << "Optimal train swapping takes " << swap << " swaps."<<endl;
  }
  return 0;
}
