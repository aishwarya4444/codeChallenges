/*
https://cses.fi/problemset/task/2165
*/

#include <bits/stdc++.h>
using namespace std;

void hanoi(int from, int to, int aux, int n) {
  if(n==0) return;

  // move n-1 disks from left tower to middle tower
  hanoi(from, aux, to, n-1);

  // move number n disk from left tower to right tower
  // cout<<n<<" : "<<from<<' '<<to<<endl;
  cout<<from<<' '<<to<<endl;

  // move n-2 disks from middle tower to right tower
  hanoi(aux, to, from, n-1);
}

int main(){

  int n;

  cin>>n;

  cout<<(1<<n)-1<<endl;
  hanoi(1, 3, 2, n);

  return 0;
}
