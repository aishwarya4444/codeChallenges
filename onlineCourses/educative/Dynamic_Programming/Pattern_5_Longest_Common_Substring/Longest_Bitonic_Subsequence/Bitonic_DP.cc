// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5755034180517888

#include<iostream>
#include<vector>
using namespace std;

void bitonic(vector<int> &v) {
  int N=v.size(), i, j, length=0;
  int lis[N], lds[N];
  lis[0] = 1;
  lds[0] = 1;
  for(i=1; i<N; i++) {
    lis[i] = lds[i] = 1;
    for(j=0; j<i; j++) {
      if(v[i]>v[j] && lis[i]<lis[j]+1) {
        lis[i] = lis[j]+1;
      }
    }
  }
  for(i=N-2; i>=0; i--) {
    for(j=N-1; j>i; j--) {
      if(v[i]>v[j] && lds[i]<lds[j]+1) {
        lds[i] = lds[j]+1;
      }
    }
  }
  for(i=0; i<N; i++) {
    length = max(length, lis[i]+lds[i]);
  }
  cout<<length-1<<'\n';
}

int main(void) {
  vector<int> v;

  // [ 4, 2, 3, 6, 10, 1, 12 ]
  v.push_back(4);
  v.push_back(2);
  v.push_back(3);
  v.push_back(6);
  v.push_back(10);
  v.push_back(1);
  v.push_back(12);
  bitonic(v);

  // [ 4, 2, 5, 9, 7, 6, 10, 3, 1 ]
  v.clear();
  v.push_back(4);
  v.push_back(2);
  v.push_back(5);
  v.push_back(9);
  v.push_back(7);
  v.push_back(6);
  v.push_back(10);
  v.push_back(3);
  v.push_back(1);
  bitonic(v);

  return 0;
}

