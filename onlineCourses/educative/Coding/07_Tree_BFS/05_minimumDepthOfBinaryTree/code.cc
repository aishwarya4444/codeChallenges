// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5666083260334080

using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    queue<TreeNode*> q;
    int n;
    if(root) {
      q.push(root);
    }
    while(q.size()) {
      n=q.size();
      minimumTreeDepth++;
      while(n--) {
        root=q.front();
        q.pop();
        if(!root->left && !root->right) {
          return minimumTreeDepth;
        }
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
      }
    }
    // TODO: Write your code here
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
