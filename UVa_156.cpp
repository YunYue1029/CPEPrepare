#include<iostream>
#include<sstream>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  unordered_map<string, vector<string>> anagram_map;
  vector<string> words;

  string line, word;

  while(getline(cin, line)){
    if(line == "#") break;

    stringstream ss(line);
    while(ss >> word){
      words.push_back(word);
      string sort_word = word;

      transform(sort_word.begin(), sort_word.end(), sort_word.begin(), ::tolower);
      sort(sort_word.begin(), sort_word.end());

      anagram_map[sort_word].push_back(word);
    }
  }

  vector<string> result;
  for(const auto& w : words){
    string sorted_w = w;
    
    transform(sorted_w.begin(), sorted_w.end(), sorted_w.begin(), ::tolower);
    sort(sorted_w.begin(), sorted_w.end());

    if(anagram_map[sorted_w].size() == 1){
      result.push_back(w);
    }
  }
  sort(result.begin(), result.end());

  for(const string& ans : result){
    cout<<ans<<endl;
  }
  return 0;
}
