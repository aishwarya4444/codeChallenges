/*
https://cses.fi/problemset/task/1755
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

  string st, ans="";
  map<char, int> mp;
  int uniq = 0, freq;

  cin>>st;

  for(char ch: st) {
    mp[ch]++;
  }

  for(char ch='A'; ch<='Z'; ch++) {
    freq = mp[ch];
    if(freq == 0) continue;
    // only 1 odd frequency character allowed
    if(freq%2 == 1) {
      uniq++;
      if(uniq == 2) {
        cout<<"NO SOLUTION";
        return 0;
      }
      // "A" will be inserted in centre
      // "AAA" will have 1 "A" in centre and remaining "A" on both sides
      ans.insert(ans.begin()+ans.size()/2, ch);
    }
    ans = string(freq/2, ch) + ans + string(freq/2, ch);
  }

  cout<<ans;

  return 0;
}
