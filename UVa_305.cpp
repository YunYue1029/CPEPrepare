#include<iostream>

using namespace std;

int find_min_m(int k){
  int m = k + 1;
  while(true){
    bool all_bad = true;
    int pos = 0;

    for(int i = 0; i < k; i++){
      pos = (pos + m) % (2 * k - i);
      if(pos < k){
        all_bad = false;
        break;
      }
    }
    if(all_bad){
      return m + 1;
    }
    m++;
  }
}
int main(){
  int k;
  while(cin >> k && k != 0){
    cout << find_min_m(k) << endl;
  }
  return 0;
}
