#include<iostream>
//#include<sstream>
#include<string>
#include<iomanip>
#include<cctype>

using namespace std;

long long toDecimal(const string &num, int frombase){
  long long decimalValue = 0;
  for(char digit : num){
    decimalValue *= frombase;
    if(isdigit(digit)){
      decimalValue += digit - '0';
    }else{
      decimalValue += toupper(digit) - 'A' + 10;
    }
  }
  return decimalValue;
}

string fromDecimal(long long num, int tobase){
  if(num == 0) return "0";

  string result = "";
  while(num > 0){
    int remainder = num % tobase;
    if(remainder < 10){
      result = char('0' + remainder) + result;
    }else{
      result = char('A' + remainder - 10) + result;
    }
    num /= tobase;
  }
  return result;
}

int main(){
  string num;
  int frombase,tobase;
  while(cin >> num >> frombase >> tobase){
    long long dvalue = toDecimal(num, frombase);
    string bvalue = fromDecimal(dvalue, tobase);
    if(bvalue.length() > 7){
      cout << setw(7) << "ERROR" << endl;
    }else{
      cout << setw(7) << bvalue << endl;
    }
  }
  return 0;
}
