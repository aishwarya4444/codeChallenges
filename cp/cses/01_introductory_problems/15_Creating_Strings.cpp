/*
https://cses.fi/problemset/task/1622
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

  string st;
  vector<string> ans;

  cin>>st;

  sort(st.begin(), st.end());

  do {
    ans.push_back(st);
  } while(next_permutation(st.begin(), st.end()));

  cout<<ans.size()<<endl;
  for(string s: ans) {
    cout<<s<<endl;
  }

  return 0;
}
