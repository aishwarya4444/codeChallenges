// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5706163895140352

using namespace std;

#include <iostream>
#include <queue>
#include <stack>

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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    // TODO: Write your code here
    vector<int> r;
    stack<TreeNode*> s1, s2;
    int n;
    if(root) {
      s1.push(root);
    }
    while(s1.size() || s2.size()) {
      while(s1.size()) {
        root=s1.top();
        s1.pop();
        r.push_back(root->val);
        if(root->left)s2.push(root->left);
        if(root->right)s2.push(root->right);
      }
      if(r.size()) {
        result.push_back(r);
        r.clear();
      }
      while(s2.size()) {
        root=s2.top();
        s2.pop();
        r.push_back(root->val);
        if(root->right)s1.push(root->right);
        if(root->left)s1.push(root->left);
      }
      if(r.size()) {
        result.push_back(r);
        r.clear();
      }
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
