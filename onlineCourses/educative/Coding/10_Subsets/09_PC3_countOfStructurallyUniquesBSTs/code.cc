// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5745189578604544

using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class CountUniqueTrees {
 public:
  int countTrees(int n) {
    int count = 0;
    // TODO: Write your code here
    int i, j, dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(i=2; i<=n; i++) {
      for(j=0; j<i; j++) {
        dp[i] += dp[j]*dp[i-j-1];
      }
    }
    count = dp[n];
    return count;
  }
};

int main(int argc, char *argv[]) {
  CountUniqueTrees ct;
  int count = ct.countTrees(3);
  cout << "Total trees: " << count;
}
