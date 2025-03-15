#include<iostream>

using namespace std;

int main(){
  char c;
  bool open = 1;
  while(cin.get(c)){
    if( c == '"'){
      if( open ){
        cout<<"``";
        open = 0;
      }else{
        cout<<"''";
        open = 1;
      }
    }else{
      cout<<c;
    }
  }
  return 0;
}
