#include<iostream>
#include<vector>

using namespace std;

vector<int> fib;

void getFib(){
  int next = 0;
  int count = 2;
  fib.push_back(1);
  fib.push_back(2);
  while(true){
    next = fib[count - 1] + fib[count - 2];
    if(next > 100000000){
      break;
    }else{
      fib.push_back(next);
    }
    count++;
  }
}

string toString(int number){
  string result = "";
  bool start = false;
  for(int  i = fib.size() - 1; i >= 0; i--){
    if(number >= fib[i]){
      start = true;
      number -= fib[i];
      result +='1';
    }else if(start){
      result += '0';
    }
  }
  return result;
}

int main(){
  int N;
  cin >> N;
  getFib();
  while(N--){
    int number;
    cin >> number;
    cout << number << " = " << toString(number) << " (fib)" << endl;
  }
  return 0;
}
