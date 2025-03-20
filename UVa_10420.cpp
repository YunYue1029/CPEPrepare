#include<iostream>
#include<string>
#include<map>
#include<sstream>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  map<string, int> countryCount;
  while(n--){
    string line, country;
    getline(cin, line);
    stringstream ss(line);

    ss >> country;
    countryCount[country]++;
  }

  for(auto const& entry : countryCount){
    cout << entry.first << " " << entry.second << endl;
  }
  return 0;
}
