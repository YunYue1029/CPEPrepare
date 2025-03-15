#include<iostream>
#include<cmath>

using namespace std;

void findTerm(int n){
  int k = ceil( ( -1 + sqrt( 1 + n * 8 )) / 2);
  int prev_sum  = k * ( k - 1 ) / 2;
  int b,e;
  if( k % 2 == 0){
    b = n - prev_sum;
    e = k + 1 - n + prev_sum;
  }else{
    b = k + 1 -n + prev_sum;
    e = n - prev_sum;
  }
  cout<<"TERM "<<n<<" IS "<<b<<"/"<<e<<endl;
}

int main(){
  int n;
  while(cin>>n){
    findTerm(n);
  }
  return 0;
}
