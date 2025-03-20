#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int r;
    cin >> r;
    vector<int> streets(r);
    for(int i = 0; i < r; i++){
      cin >> streets[i];
    }

    sort(streets.begin(), streets.end());
    
    int mid = streets[r/2];

    int min_distance = 0;
    for(int i = 0; i < r; i++){
      min_distance += abs(streets[i] - mid);
    }

    cout << min_distance <<endl;
  }
  return 0;
}
