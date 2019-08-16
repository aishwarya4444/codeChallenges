// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5726607939469312

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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    vector<int> r;
    queue<TreeNode*> q;
    int n;
    if(root) {
      q.push(root);
    }
    while(q.size()) {
      n=q.size();
      while(n--) {
        root = q.front();
        q.pop();
        r.push_back(root->val);
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
      }
      result.push_back(r);
      r.clear();
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
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
