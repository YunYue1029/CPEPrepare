#include<iostream>
#include<vector>

using namespace std;

int main(){
  string input;
  vector<string> result;
  while(getline(cin, input)){
    string word = "";

    for (char c : input) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                result.push_back(word);
                cout << word ;
            }
            if(isdigit(c)){
                int num = int(c - '0');
                cout << result[result.size() - num];
                //result.push_back(result[result.size() - num]);
            }else{
              cout << c;
            }
            word = "";
        }
    }
    if (!word.empty()) {
        result.push_back(word);
        cout << word;
    }
    cout << endl;
    
  }
  return 0;
}
