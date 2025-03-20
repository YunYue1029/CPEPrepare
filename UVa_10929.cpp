#include<iostream>
#include<string>

using namespace std;

bool isMultiple(string& num){
  int odd = 0, even = 0;
  for(int i = 0 ; i < num.length(); i++){
    if(i % 2){
      odd += (num[i] - '0');
    }else{
      even += (num[i] - '0');
    }
  }
  return (abs(odd - even) % 11 == 0);
}

int main(){
  string num;
  while(cin >> num, num != "0"){
    if(isMultiple(num)){
      cout << num << " is a multiple of 11." << endl;
    }else{
      cout << num << " is not a multiple of 11." << endl;
    }
  }
  return 0;
}
