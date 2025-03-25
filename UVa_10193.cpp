#include<iostream>
#include<string>

using namespace std;

int toD(string s){
  int result = 0;
  for(char c : s){
    result = result * 2 + c - '0';
  }
  return result;
}

int gcd(int a, int b){
  while(b != 0){
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main(){
  int N;
  string s1, s2;
  cin >> N;
  while(N--){
    cin >> s1 >> s2;
    long long s1Value = toD(s1);
    long long s2Value = toD(s2);
    int result = gcd(s1Value, s2Value);
    if(result > 1){
      cout << "Pair #1: All you need is love!" << endl;
    }else{
      cout << "Pair #2: Love is not all you need!" << endl;
    }
  }
  return 0;
}
