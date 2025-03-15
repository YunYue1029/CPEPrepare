#include<iostream>
using namespace std;

int count(int n)
{
  int c = 1;
  while(n != 1)
  {
    if(n%2)
    {
      n = 3*n+1;
    }
    else
    {
      n/=2;
    }
    c++;
  }
  return c;
}

int main()
{
  int i,j;
  int max_number = 0;
  while(cin>>i>>j)
  {
    max_number = 0;
    int start = min(i,j);
    int end = max(i,j);
    for(int number = start;number<=end;number++)
    {
      max_number = max(max_number,count(number));
    }
    cout<<i<<" "<<j<<" "<<" "<<max_number<<endl;
  }
  return 0;
}
