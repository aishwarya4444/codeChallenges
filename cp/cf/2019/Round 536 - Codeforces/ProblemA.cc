// http://codeforces.com/contest/1106/problem/A

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int solve(vector<string> &v) {
  int count=0, r, c, N=v.size();
  for(r=1;r<=N-2;r++) {
    for(c=1;c<=N-2;c++) {
      if(v[r][c] == 'X' && v[r-1][c-1] == 'X' && v[r+1][c+1] == 'X' && v[r+1][c-1] == 'X' && v[r-1][c+1] == 'X') {
        count++;
      }
    }
  }
  return count;
}

int main(void ) {
  vector<string> v;
  string s;
  int N;
  cin>>N;
  while(N--) {
    cin>>s;
    v.push_back(s);
  }
  cout<<solve(v)<<'\n';
  return 0;
}
