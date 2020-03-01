#include<iostream>
#include<vector>
#define LLI long long int
using namespace std;

int main() {
  LLI t, tiles, T, prevMax, r1, r2, r3;
  vector<vector<LLI> > cost;

  cin>>T;
  while(T--) {
    cin>>tiles;

    cost = vector<vector<LLI> >(tiles, vector<LLI>(3, 0));

    for(t=0; t<tiles; t++) {
      cin>>cost[t][0]>>cost[t][1]>>cost[t][2];
    }

    for(t=0; t<tiles; t++) {
      r1 = (t>=1) ? cost[t-1][0] : -99999;
      r2 = (t>=2) ? cost[t-2][1] : -99999;
      r3 = (t>=3) ? cost[t-3][2] : -99999;

      prevMax = max(r1, max(r2, r3));

      if(prevMax == -99999) {
        prevMax = 0;
      }

      cost[t][0] += prevMax;
      cost[t][1] += prevMax;
      cost[t][2] += prevMax;

    }

    r1 = (tiles>=1) ? max(cost[tiles-1][0], max(cost[tiles-1][1], cost[tiles-1][2])) : -99999;
    r2 = (tiles>=2) ? max(cost[tiles-2][1], cost[tiles-2][2]) : -99999;
    r3 = (tiles>=3) ? cost[tiles-3][2] : -99999;

    cout<<max(r1, max(r2, r3))<<endl;
    cost.clear();
  }

  return 0;
}
