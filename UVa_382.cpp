#include<iostream>
#include<string>

using namespace std;

long long check(long long num){
  long long sum = 0;
  for(int i = 0; i * i <= num ; i++){
    if(num % i == 0){
      sum += i;
      if(i * i != num){
        sum += num / i;
      }
    }
  }
  return sum;
}

string classifyNumber(long long num){
  long long sum = check(num);
  if(sum == num) return "PERFECT";
  else if(sum > num) return "ABUNDANT";
  else return "DEFICIENT";
}

int main(){
  cout << "PERFECTION OUTPUT" << endl;

  long long num;
  while(cin >> num && num != 0){
    cout.width(5);
    cout << right << num << " " << classifyNumber(num) << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
