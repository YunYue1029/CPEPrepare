#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  string line;
  vector<string> allstring;
  int maxlength = 0;
  while(getline(cin, line)){
    allstring.push_back(line);
    maxlength = max(maxlength, (int)line.length());
  }
  int row = allstring.size();
  for(int i = 0; i < maxlength; i++){
    for(int j = row - 1; j >= 0; j--){
      if(i < allstring[j].size()){
        cout << allstring[j][i];
      }else{
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
