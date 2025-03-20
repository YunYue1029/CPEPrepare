#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

string departNum(long long num){
    if(num == 0)return 0;
    string result = "";
    
    if(num > 10000000){
      result += to_string(num / 10000000);
      result += " kati";
      num %= 10000000;
    }

    if(num > 100000){
      result += " ";
      result += to_string(num / 100000);
      result += " lakh";
      num %= 100000;
    }

    if(num > 1000){
      result += " ";
      result += to_string(num / 1000);
      result += " hajar";
      num %= 1000;
    }

    if(num > 100){
      result += " ";
      result += to_string(num / 100);
      result += " shata";
      num %= 100;
    }

    if(num > 0){
      result += " ";
      result += to_string(num);
    }

    return result;
}

int main(){
  long long num;
  int caseNum = 1;
  while(cin >> num){
    cout << setw(4) << right << caseNum++ << ". " << departNum(num) << endl;
  }
}
