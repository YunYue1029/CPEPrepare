#include<iostream>

using namespace std;

int toD(int number){
  int result = 0;
  while(number > 0){
    if(number % 2 == 1){
      number = number - 1;
      result++;
    }
    number /= 2;
  }
  return result;
}

int toH(int number){
  int result = 0;
  int ten = 0;
  int times = 0;
  while(number > 0){
    ten += (number % 10 * pow(16, times++));
    number /= 10;
  }
  //cout << ten << endl;
  while(ten > 0){
    if(ten % 2 == 1){
      ten = ten - 1;
      result++;
    }
    ten /= 2;
  }
  return result;
}

int main(){
  int N;
  cin >> N;
  while(N--){
    int number;
    cin >> number;
    cout << toD(number) << " " << toH(number) << endl;
  }
  return 0;
}
