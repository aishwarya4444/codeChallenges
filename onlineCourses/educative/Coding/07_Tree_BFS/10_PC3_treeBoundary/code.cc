// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5760744339537920

using namespace std;

#include <deque>
#include <iostream>
#include <queue>
#include <stack>
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

// https://leetcode.com/problems/boundary-of-binary-tree/

class TreeBoundary {
 public:
  static void getLeaves(vector<TreeNode*> &result, TreeNode *root) {
    if(!root) return;
    if(!root->left && !root->right) {
      result.push_back(root);
      return;
    }
    getLeaves(result, root->left);
    getLeaves(result, root->right);
  }

  static vector<TreeNode *> findBoundary(TreeNode *root) {
    vector<TreeNode *> result;
    // TODO: Write your code here
    stack<TreeNode*> rightView;
    TreeNode *node;
    if(!root) {
      return result;
    }
    // add root node
    result.push_back(root);
    // get left boundary
    node = root->left;
    while(node) {
      if(node->left || node->right) {
        result.push_back(node);
      }
      if(node->left) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    // get leaves
    getLeaves(result, root->left);
    getLeaves(result, root->right);
    // get right boundary
    node = root->right;
    while(node) {
      if(node->left || node->right) {
        rightView.push(node);
      }
      if(node->right) {
        node = node->right;
      } else {
        node = node->left;
      }
    }
    while(rightView.size()) {
      result.push_back(rightView.top());
      rightView.pop();
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->left->left->left = new TreeNode(9);
  root->left->right = new TreeNode(3);
  root->left->right->left = new TreeNode(15);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->right->left = new TreeNode(6);
  vector<TreeNode *> result = TreeBoundary::findBoundary(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}
