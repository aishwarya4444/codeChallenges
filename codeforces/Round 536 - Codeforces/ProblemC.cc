// http://codeforces.com/contest/1106/problem/C

#include<iostream>
#include<vector>
#include<algorithm>
#define ULLI unsigned long long int
using namespace std;

ULLI solve(vector<size_t> &v) {
  int i=0, j=v.size()-1;
  size_t sum;
  ULLI result=0;
  sort(v.begin(), v.end());
  while(i<j) {
    sum = v[i]+v[j];
    result += sum*sum;
    i++;
    j--;
  }
  return result;
}

int main(void ) {
  vector<size_t> v;
  size_t n;
  int N;
  cin>>N;
  while(N--) {
    cin>>n;
    v.push_back(n);
  }
  cout<<solve(v)<<'\n';
  return 0;
}
