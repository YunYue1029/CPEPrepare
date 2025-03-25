#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>

using namespace std;

int main(){
  int x;
  string line;
  while(cin >> x){
    cin.ignore();
    vector<int> coeff;
    getline(cin, line);
    stringstream ss(line);
    int a;
    while(ss >> a){
      coeff.push_back(a);
    }

    int n = coeff.size();
    long long result = 0;
    for(int i = 0; i < n - 1; i++){
      int  power = n - 1 - i;
      result += ((long long)coeff[i] * power * pow(x, power - 1));
    }
    cout << result << endl;

  }
  return 0;
}
