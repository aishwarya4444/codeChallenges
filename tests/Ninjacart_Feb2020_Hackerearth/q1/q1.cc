#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

int main() {
  string s, t;
  int c, T;
  bool result;
  unordered_map<int, int> count;

  cin>>T;
  while(T--) {
    cin>>s>>t;
    result = true;

    if(s.size() != t.size()) {
      cout<<"NO\n";
      continue;
    }

    for(auto chr: s) {
      count[chr-'a']++;
    }

    for(auto chr: t) {
      count[chr-'a']++;
    }

    for(auto entry: count) {
      if((entry.second)%2) {
        result = false;
        break;
      }
    }

    if(result) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }

    count.clear();
  }

  return 0;
}
