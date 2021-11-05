/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int bit[26][N];
string str;
int n, q;

int lsb(int i) {
  return (i&(-i));
}

void update(int ch, int i, int val) {
  for(i; i<=n; i+=lsb(i)) {
    bit[ch][i] += val;
  }
}

int query(int ch, int i) {
  int sum = 0;
  for(i; i>0; i-=lsb(i)) {
    sum += bit[ch][i];
  }
  return sum;
}

int main(){
  cin>>n>>q;
  cin>>str;
  cin.ignore();

  str = '_'+str;
  for(int i=1; i<=n; i++) {
    update(str[i]-'a', i, 1);
  }

  while(q--) {
    int type;
    cin>>type;

    if(type==1) {
      // update
      int L;
      char x;
      cin>>L;
      cin>>x;
      update(str[L]-'a', L, -1);
      update(x-'a', L, 1);
      str[L] = x;
    } else {
      // query
      int L, R;
      int odd=0, even=0, freq;
      cin>>L>>R;
      for(int i=0; i<26; i++) {
        freq = query(i, R) - query(i, L-1);
        if(freq%2) {
          odd++;
        } else {
          even++;
        }
      }
      if((R-L+1)%2) {
        // for odd length strings only 1 odd occurence should happen
        if(odd!=1) {
          cout<<"no\n";
        } else {
          cout<<"yes\n";
        }
      } else {
        // for even length strings 0 odd occurence should happen
        if(odd)  {
          cout<<"no\n";
        } else {
          cout<<"yes\n";
        }
      }
    }
  }

  return 0;
}
