#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
  vector<int> nums;
  int num;
  long int pos, step=1, N, Q;
  string op;

  cin>>N;

  while(N--) {
    cin>>num;
    nums.push_back(num);
  }

  cin>>Q;
  N = nums.size();

  while(Q--) {
    cin>>op;

    if(op[0]=='I') {
      cin>>pos;
      nums[(N+pos-step)%N]++;
    } else if(op[0]=='U') {
      cin>>pos>>num;
      nums[(N+pos-step)%N] = num;
    } else if(op[0]=='L') {
      step--;
      // nums.push_back(nums[0]);
      // nums.erase(nums.begin());
    } else if(op[0]=='R') {
      step++;
      // nums.insert(nums.begin(), nums[N-1]);
      // nums.pop_back();
    } else {
      cin>>pos;
      cout<<nums[(N+pos-step)%N]<<endl;
    }
  }

  return 0;
}

/*
10
0 3 3 8 0 6 9 3 2 8
10
Increment 3
Increment 1
Left
Increment 5
Left
? 9
Right
Left
Left
? 4
*/
