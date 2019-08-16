// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5682747733442560

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

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

class RightViewTree {
 public:
  static vector<TreeNode *> traverse(TreeNode *root) {
    vector<TreeNode *> result;
    // TODO: Write your code here
    queue<TreeNode*> q;
    int n;
    if(root) {
      q.push(root);
    }
    while(q.size()) {
      n=q.size();
      while(n--) {
        root=q.front();
        q.pop();
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
      }
      result.push_back(root);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->left->left->left = new TreeNode(3);
  vector<TreeNode *> result = RightViewTree::traverse(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}
