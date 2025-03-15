#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

vector<char> directions = {'N', 'E', 'S', 'W'};
vector< pair<int, int> > movement = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int get_direction(char D){
  for(int i = 0 ; i < 4 ; ++i){
    if(directions[i] == D) return i;
  }
  return -1;
}

int main(){
  int row,col;
  int X,Y;
  char D;
  int isFall = 0;
  int new_X = 0,new_Y = 0;
  string command;
  set< pair<int,int> > fall_part;
  cin>>row>>col;
  while(cin>>X>>Y>>D){
    int int_dir = get_direction(D);
    cin>>command;
    for(int i = 0 ; i < command.length() ; ++i){
      if(command[i] == 'R'){
        int_dir = (int_dir + 1)%4;
      }
      else if(command[i] == 'L'){
        int_dir = (int_dir + 3)%4;
      }
      else if(command[i] == 'F'){
        new_X = X + movement[int_dir].first;
        new_Y = Y + movement[int_dir].second;

        if(new_X > row || new_Y > col || new_X < 0 || new_Y < 0){
          if(fall_part.count(make_pair(X,Y))){
            continue;
          }
          else{
            isFall = 1;
            fall_part.insert({X,Y});
            break;
          }
        }
        X = new_X;
        Y = new_Y;
      }
      //cout<<X<<" "<<Y<<" "<<directions[int_dir]<<endl;
    }
    cout<<X<<" "<<Y<<" "<<directions[int_dir];
    if(isFall){
      cout<<" "<<"LOST";
      isFall = 0;
    }
    cout<<endl;
  }
}
