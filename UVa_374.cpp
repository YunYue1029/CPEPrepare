#include<iostream>

using namespace std;

int main(){
  int B,P,M;
  long long result = 1;
  while(true){
    cin >> B >> P >> M;
    for(int i = 0; i < P ; i++){
      result = result * B % M;
    }
    cout << result << endl;
  }
  return 0;
}
