/*
https://www.spoj.com/problems/MATSUM/

https://github.com/RohitJV/spoj-solutions/blob/master/MATSUM.cpp
https://github.com/rezwan4029/SPOJ-solutions/blob/master/1029%20Matrix%20Summation%20%5B%20MATSUM%20%5D.cpp
https://github.com/UtopiaBeam/SPOJ/blob/master/MATSUM.cpp
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1025;

int bit[N][N];
int t, n;

int lsb(int i) {
  return (i&(-i));
}

void update(int i, int j, int val) {
  for(int x=i; x<=n; x+=lsb(x)) {
    for(int y=j; y<=n; y+=lsb(y)) {
      bit[x][y] += val;
    }
  }
}

int query(int i, int j) {
  int sum = 0;
  for(int x=i; x>0; x-=lsb(x)) {
    for(int y=j; y>0; y-=lsb(y)) {
      sum += bit[x][y];
    }
  }
  return sum;
}

int range_query(int x1, int y1, int x2, int y2) {
  int ans = query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1);
  return ans;
}

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  // cin>>t;
  scanf("%d", &t);

  while(t--) {

    // cin>>n;
    scanf("%d", &n);

    memset(bit, 0, sizeof bit);

    int x1, y1, x2, y2, num;
    char query[5];

    while(true) {
      // cin>>query;
      scanf("%s", &query);

      if(query[1]=='E') {
        // cin>>x1>>y1>>num;
        scanf("%d %d %lld", &x1, &y1, &num);
        x1++;
        y1++;
        int curval = range_query(x1, y1, x1, y1);
        update(x1, y1, num - curval);
      } else if(query[1]=='U'){
        // cin>>x1>>y1>>x2>>y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1++;
        y1++;
        x2++;
        y2++;
        printf("%d\n", range_query(x1, y1, x2, y2));;
      } else {
        break;
      }

    }

  }

  return 0;
}
