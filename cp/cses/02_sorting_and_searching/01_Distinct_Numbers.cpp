/*
https://cses.fi/problemset/task/1621
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, num;
  set<int> st;

  cin>>n;

  while(n--) {
    cin>>num;
    st.insert(num);
  }

  cout<<st.size();

  return 0;
}
