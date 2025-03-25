#include<iostream>

using namespace std;

int main(){
  int N;
  int count = 0;
  cin >> N;
  while(N--){
    count++;
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for(int i = a; i <= b; i++){
      if(i % 2 == 1){
        sum += i;
      }
    }
    cout << "Case " << count << ": "<< sum << endl;
  }
  return 0;
}
