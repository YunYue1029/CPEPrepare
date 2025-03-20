#include<iostream>
#include<string>
#include<map>
#include<cctype>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  map<char, int> freq;
  while(n--){
    string line;
    getline(cin, line);
    for(char c : line){
      if(isalpha(c)){
        char upperC = toupper(c);
        freq[upperC]++;
      }
    }
  }
  vector<pair<char, int>> sortfreq(freq.begin(), freq.end());
  
  sort(sortfreq.begin(), sortfreq.end(), [](pair<char, int> a, pair<char, int> b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
  });

  for(auto const& entry : sortfreq){
    cout << entry.first << " " << entry.second << endl;
  }
  return 0;
}
