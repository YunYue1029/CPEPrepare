#include<iostream>
//#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  int L,H,R;
  vector<int> build(50001,0);

  while(cin>>L>>H>>R)
  {
    for(int i = L;i < R;i++)
    {
      build[i] = max(build[i],H);
    }
  }
  int height = 0;
  for(int i = 0; i < 50001;i++ )
  {
    if(height != build[i])
    {
      cout<<i<<" "<<build[i]<<" ";
      height = build[i];
    }
  }
  cout<<endl;
  return 0;
}

