#include<iostream>
#include<vector>

using namespace std;

int main(){
  int N;
  while(cin >> N, N != 0){
    int count = 0;
    vector<int> b;
    while(N > 0){
      if(N % 2 ==1){
        count++;
        b.push_back(1);
      }else{
        b.push_back(0);
      }
      N /= 2;
    }
    cout << "The parity of ";
    for(int i = b.size() - 1; i >= 0; i--){
      cout << b[i];
    }
    cout << " is " << count << " (mod 2)."<< endl;
  }
  return 0;
}
