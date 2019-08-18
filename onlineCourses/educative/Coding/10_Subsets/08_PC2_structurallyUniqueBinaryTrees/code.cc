// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5679974795182080

using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class UniqueTrees {
 public:
  static vector<TreeNode *> findUniqueTrees(int n) {
    vector<TreeNode *> result;
    // TODO: Write your code here
    result = help(1, n);
    return result;
  }
  static vector<TreeNode *> help(int l, int r) {
    vector<TreeNode *> result;
    if(l>r) {
      result.push_back(NULL);
      return result;
    }
    for(int i=l; i<=r; i++) {
      vector<TreeNode *> leftTrees = help(l, i-1);
      vector<TreeNode *> rightTrees = help(i+1, r);
      for(int j=0; j<leftTrees.size(); j++) {
        for(int k=0; k<rightTrees.size(); k++) {
          TreeNode *root = new TreeNode(i);
          root->left = leftTrees[j];
          root->right = rightTrees[k];
          result.push_back(root);
        }
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<TreeNode *> result = UniqueTrees::findUniqueTrees(2);
  cout << "Total trees: " << result.size() << endl;

  result = UniqueTrees::findUniqueTrees(3);
  cout << "Total trees: " << result.size() << endl;
}
