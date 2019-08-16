// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5769720821186560

#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class MaximumPathSum {
  private:
    static int maxPath(TreeNode* root, int &globalMaxSum) {
      if(!root) return 0;
      int lsum=0, rsum=0;
      lsum = max(0, maxPath(root->left, globalMaxSum));
      rsum = max(0, maxPath(root->right, globalMaxSum));
      globalMaxSum = max(globalMaxSum, root->val+lsum+rsum);
      return root->val+max(lsum, rsum);
    }
  public:
    static int findMaximumPathSum(TreeNode *root) {
      // TODO: Write your code here
      int globalMaxSum = INT_MIN;
      maxPath(root, globalMaxSum);
      return globalMaxSum;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}
