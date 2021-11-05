/*
https://www.spoj.com/problems/INVCNT/
Point Update & Range Query

Only BIT has 2 problems:
[1] Negative values cannot be handled
[2] If maximum value is large, then we need more storage

Solution is to use co-ordinate compression
*/

// BIT with co-ordinate compression
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 200001;

int bit[N];
int a[N];
int t, n;
set<int> num;
unordered_map<int, int> id;

void update(int i, int val) {
  while(i<=N) {
    bit[i] += val;
    i += (i&(-i));
  }
}

int query(int i) {
  int sum = 0;
  while(i>0) {
    sum += bit[i];
    i -= (i&(-i));
  }
  return sum;
}

void coordinate_compression() {
  for(int i=1; i<=n; i++) {
    num.insert(a[i]);
  }

  int count = 1;
  for(auto n: num) {
    id[n] = count;
    count++;
  }
}

int main(){
  cin>>t;

  while(t--) {

    cin>>n;

    memset(bit, 0, sizeof bit);
    memset(a, 0, sizeof a);
    num.clear();
    id.clear();

    for(int i=1; i<=n; i++) {
      cin>>a[i];
    }

    coordinate_compression();

    ll ans = 0;
    for(int i=n; i>=1; i--) {
      update(id[a[i]], 1);
      ans += query(id[a[i]]-1);
    }
    cout<<ans<<endl;
  }

  return 0;
}

// BIT only
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 200001;
const int M = 10000001;

int bit[M];
int a[N];
int t, n;

void update(int i, int val) {
  while(i<=M) {
    bit[i] += val;
    i += (i&(-i));
  }
}

int query(int i) {
  int sum = 0;
  while(i>0) {
    sum += bit[i];
    i -= (i&(-i));
  }
  return sum;
}

int main(){
  cin>>t;

  while(t--) {

    cin>>n;

    memset(bit, 0, sizeof bit);
    memset(a, 0, sizeof a);

    for(int i=1; i<=n; i++) {
      cin>>a[i];
    }

    ll ans = 0;
    for(int i=n; i>=1; i--) {
      update(a[i], 1);
      ans += query(a[i]-1);
    }
    cout<<ans<<endl;
  }

  return 0;
}
