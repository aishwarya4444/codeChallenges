// http://codeforces.com/contest/1111/problem/A

#include<iostream>
#include<cstring>
using namespace std;

void solve(string s, string t) {
  int S=s.size(), T=t.size(), i;
  bool vowels_s=false, vowels_t=false;
  if(S != T) {
    cout<<"No\n";
    return;
  }
  for(i=0;i<S;i++) {
    vowels_s = false;
    vowels_t = false;
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')vowels_s=true;
    if(t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u')vowels_t=true;
    if(vowels_t ^ vowels_s) {
      cout<<"No\n";
      return;
    }
  }
  cout<<"Yes\n";
  return;
}

int main(void ) {
  string s, t;
  cin>>s>>t;
  solve(s,t);
  return 0;
}
