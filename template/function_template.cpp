#include <iostream>
using namespace std;


template <typename T>
T minFunc(T x,T y,bool l)
{

  l = true;
  return(x<y)?x:y;
}

int main(){
  bool flag = false;
  int n1 = 2, n2 =10;

  double d1 = 2.3 , d2 = 4.5;
  cout<<"min of int:"<<minFunc(n1,n2,flag)<<endl;
  cout<<"min of dou:"<<minFunc(d1,d2,flag)<<endl;
  return 0;
}
