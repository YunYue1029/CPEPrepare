#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int a, b;
  while(cin >> a >> b, a != 0 && b != 0){
    int low = ceil(sqrt(a));
    int high = floor(sqrt(b));
    int result = max(0, high - low + 1);
    cout << result << endl;
  }
  return 0;
}
