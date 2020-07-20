// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5691878833913856

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

// https://leetcode.com/problems/diameter-of-binary-tree/

class TreeDiameter {
  private:
    static int treeHeight(TreeNode *root, int &diameter) {
      if(!root) return 0;
      int lh = 0, rh=0;
      lh = treeHeight(root->left, diameter);
      rh = treeHeight(root->right, diameter);
      diameter = max(diameter, 1+lh+rh);
      return 1+max(lh, rh);
    }
  public:
    static int findDiameter(TreeNode *root) {
      // TODO: Write your code here
      int diameter = 0;
      treeHeight(root, diameter);
      return diameter;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
