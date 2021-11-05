/*
Problem Description:
You are given a sequence of N integers A denoted by A[1] , A[2].....A[N].
Each integer in the sequence has a value associated with it W[1],W[2].... W[N].
You have to select a subsequence of given array A such that all the elements in A are in
strictly increasing order and sum of values of elements in this selected subsequence is maximum.
You have to print this maximum value.

Input Format:
The first line of input contains a single integer T.
T test-cases follow.
The first line of each test-case contains an integer N.
The next line contains a1, a2, ..., aN separated by a single space.
The next line contains w1, w2, ..., wN separated by a single space.

Sample Input:
2
4
1 2 3 4
100 200 300 400
3
4 2 3
100 30 20

Output Format:
For each test-case output a single integer: The maximum sum of values of increasing subsequences of the given sequence.

Sample Output:
1000
100

Problem Constraints: 1 <= T <= 5
1 <= N <= 200000
1 <= a[i] <= 10^9, where i ∈ [1..N]
1 <= w[i] <= 10^9, where i ∈ [1..N]



Variation of LIS
https://www.geeksforgeeks.org/longest-increasing-subsequence-using-bit/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 200001;

ll bit[N];
int a[N];
int w[N];
int t, n;
ll ans;

int lsb(int i) {
  return (i&(-i));
}

void update(int i, ll val) {
  for(i; i<=n; i+=lsb(i)) {
    bit[i] = max(bit[i], val);
  }
}

ll query(int i) {
  ll sum = 0;
  for(i; i>0; i-=lsb(i)) {
    sum = max(bit[i], sum);
  }
  return sum;
}

void coordinate_compression() {
  unordered_map<int, int> mp;
  set<int> st;
  int id = 1;

  for(int i=1; i<=n; i++) {
    st.insert(a[i]);
  }

  for(auto num: st) {
    mp[num] = id;
    id++;
  }

  for(int i=1; i<=n; i++) {
    a[i] = mp[a[i]];
  }
}

int main(){
  cin>>t;

  while(t--) {

    ans = 0;
    memset(bit, 0, sizeof bit);

    cin>>n;

    for(int i=1; i<=n; i++) {
      cin>>a[i];
    }

    for(int i=1; i<=n; i++) {
      cin>>w[i];
    }

    coordinate_compression();

    for(int i=1; i<=n; i++) {
      ll val1 = query(a[i]-1) + w[i];
      ll val0 = query(a[i]);
      if(val1 > val0) {
        ans = max(ans, val1);
        update(a[i], val1);
      }
    }

    cout<<ans<<endl;
  }

  return 0;
}
