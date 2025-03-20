#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<string> WW = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Firday", "Saturday"};
  vector<int> DD = {0, 10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};
  int testCase;
  cin >> testCase;
  while(testCase--){
    int M, D;
    cin >> M >> D;
    int offset = D - DD[M];
    int day = (1 + offset) % 7;
    if(day < 0)day += 7;
    cout << WW[day] << endl;
  }
  return 0;
}
