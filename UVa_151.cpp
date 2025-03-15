#include<iostream>
#include<vector>

using namespace std;

bool isValidM(int N, int m){
  vector<int> regions(N);
  for(int i = 0; i < N; i++){
    regions[i] = i + 1;
  }
  regions.erase(regions.begin());
  int index = 0;
  while(regions.size() > 1){
    index = (index + m - 1) % regions.size();
    if(regions[index] == 13){
      return false;
    }
    regions.erase(regions.begin() + index);
  }
  return regions[0] == 13;
}

int findMinM(int N){
  int m = 1;
  while(!isValidM(N,m)){
    m++;
  }
  return m;
}

int main(){
  int N = 0;
  while(cin >> N && N != 0){
    cout << findMinM(N) <<endl;
  }
  return 0;
}
