#include<iostream>
#include<vector>

using namespace std;

int kadane(vector<int>& arr){
  int maxSum = INT_MIN,curSum = 0;
  for(int x = 0 ; x < 4 ; x++){
    curSum = max(arr[x],curSum+arr[x]);
    maxSum = max(maxSum,curSum);
  }

  return maxSum;
}

int maxMatrix(vector< vector<int> >& arr , int N){
  int maxSum = INT_MIN;

  for(int top = 0 ; top < N ; ++top){
    vector<int> temp(N,0);
    for(int bottom = top ; bottom < N ; ++bottom){
      for(int col = 0 ; col < N ; ++col){
        temp[col] += arr[bottom][col];
      }
      int curMax = kadane(temp);
      maxSum = max(maxSum, curMax);
    }
  }
  return maxSum;
}

int main(){
  int N;
  cin>>N;
  vector< vector<int> > matrix(N,vector<int> (N));
  for(int i = 0 ; i < N ;++i){
    for(int j = 0 ; j < N ; ++j){
      cin>>matrix[i][j];
    }
  }
  cout<<maxMatrix(matrix,N);
  return 0;
}
