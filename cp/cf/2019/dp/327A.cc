/*
https://codeforces.com/problemset/problem/327/A
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
vector<int> toLeft, toRight;
int N;

int help(int start, int end) {
  int l, r, n, total=0, zero;
  // cout<<"t s e z l r\n";
  // O(n^3) solution
  for(l=start; l<=end; l++) {
    for(r=l; r<=end; r++) {
      zero = 0;
      // O(n^2) solution without this loop
      // for(n=l; n<=r; n++) {
      //   if(a[n]==0) {
      //     zero++;
      //   }
      // }
      // cout<<total<<' '<<l<<' '<<r<<' '<<zero<<' '<<toLeft[l]<<' '<<toRight[r]<<endl;
      zero = r-l+1-(toLeft[r+1]-toLeft[l]);
      total = max(total, zero+toLeft[l]+toRight[r]);
    }
  }
  return total;
}

// O(n) solution
int kadane() {
  int ones=0, n, sum=0, maxSum=INT_MIN, num;

  for(n=0; n<N; n++) {
    if(a[n]) {
      ones++;
      num = -1;
    } else {
      num = 1;
    }

    sum += num;
    if(maxSum<sum) maxSum = sum;
    if(sum<0) sum=0;
  }
  return ones+maxSum;
}

int main() {
  int n, ones;
  cin>>N;
  a = vector<int> (N, 0);
  toLeft = vector<int> (N, 0);
  toRight = vector<int> (N, 0);

  for(n=0; n<N; n++) {
    cin>>a[n];
  }

  ones = 0;
  for(n=0; n<N; n++) {
    toLeft[n] = ones;
    if(a[n]) {
      ones++;
    }
  }
  toLeft.push_back(ones);

  ones = 0;
  for(n=N-1; n>=0; n--) {
    toRight[n] = ones;
    if(a[n]) {
      ones++;
    }
  }

  // cout<<help(0, N-1)<<endl;
  cout<<kadane()<<endl;
  return 0;
}
