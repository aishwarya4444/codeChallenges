// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5714315743068160

using namespace std;

#include <iostream>
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

class FindAllTreePaths {
  private:
    static void makePaths(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &allPaths) {
      if(!root)return;
      path.push_back(root->val);
      if(!root->left && !root->right && root->val == sum) {
        allPaths.push_back(path);
      } else {
        makePaths(root->left, sum-root->val, path, allPaths);
        makePaths(root->right, sum-root->val, path, allPaths);
      }
      path.pop_back();
    }
  public:
    static vector<vector<int>> findPaths(TreeNode *root, int sum) {
      vector<vector<int>> allPaths;
      // TODO: Write your code here
      vector<int> path;
      makePaths(root, sum, path, allPaths);
      return allPaths;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
