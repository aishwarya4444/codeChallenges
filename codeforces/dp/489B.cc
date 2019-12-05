/*
https://codeforces.com/problemset/problem/489/B
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* wrong answer for below test case
100
72 95 84 98 46 89 72 70 96 72 59 92 79 87 50 60 89 81 100 55 62 56 56 98 86 85 45 60 65 89 51 84 92 74 78 97 90 97 98 83 14 97 87 97 99 18 96 67 59 90 56 100 87 38 51 21 92 60 97 85 97 48 99 60 64 64 93 99 76 37 39 82 79 92 98 93 66 47 91 96 100 35 83 87 62 60 77 54 74 96 74 93 74 86 96 99 74 92 99 78
100
71 47 59 32 98 49 100 35 85 69 90 91 67 62 45 100 77 85 45 83 78 69 98 96 100 69 94 91 81 95 86 97 98 96 94 67 82 20 70 99 90 69 62 57 90 36 90 97 75 78 84 81 58 53 77 73 78 97 54 92 30 92 88 65 77...

struct bg {
  int b, g, d;
  bg(int boy, int girl, int diff) {
    b = boy;
    g = girl;
    d = diff;
  }
};

struct compare {
  bool operator()(const bg &bg1, const bg &bg2) {
    if(bg1.d==bg2.d) {
      if(bg1.b==bg2.b) {
        return bg1.g<bg2.g;
      }
      return bg1.b<bg2.b;
    }
    return bg1.d<bg2.d;
  }
};

int main() {
  int b, g, skill, B, G;
  vector<int> boys;
  vector<bg> bgSet;
  vector<bool> boysSelected, girlsSelected;

  cin>>B;
  boysSelected = vector<bool>(B, false);
  for(b=0; b<B; b++) {
    cin>>skill;
    boys.push_back(skill);
  }

  cin>>G;
  girlsSelected = vector<bool>(G, false);
  for(g=0; g<G; g++) {
    cin>>skill;
    for(b=0; b<B; b++) {
      if(abs(skill-boys[b])<=1) {
        bgSet.push_back({b, g, abs(skill-boys[b])});
      }
    }
  }

  sort(bgSet.begin(), bgSet.end(), compare());

  skill = 0;
  for(auto node: bgSet) {
    if(!boysSelected[node.b] && !girlsSelected[node.g]) {
      skill++;
      boysSelected[node.b] = true;
      girlsSelected[node.g] = true;
    }
  }

  cout<<skill<<endl;

  return 0;
}
*/

int main() {
  int b, g, skill, B, G;
  vector<int> boys, girls;
  vector<bool> girlSelected;

  cin>>B;
  for(b=0; b<B; b++) {
    cin>>skill;
    boys.push_back(skill);
  }

  cin>>G;
  girlSelected = vector<bool>(G, false);
  for(g=0; g<G; g++) {
    cin>>skill;
    girls.push_back(skill);
  }

  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());

  skill = 0;
  for(auto boy: boys) {
    g = -1;
    for(auto girl: girls) {
      g++;
      if(!girlSelected[g] && abs(boy-girl)<=1) {
        skill++;
        girlSelected[g] = true;
        break;
      }
    }
  }

  cout<<skill<<endl;
  return 0;
}
