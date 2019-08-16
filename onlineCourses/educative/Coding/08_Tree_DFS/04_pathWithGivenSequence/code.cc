// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5750943224168448

#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
  private:
    static bool findSequence(TreeNode *root, const vector<int> &sequence, int index) {
      if(!root) return false;
      if(root->val!=sequence[index]) return false;
      if(!root->left && !root->right) {
        if(sequence.size()==index+1) return true;
        else return false;
      }
      return findSequence(root->left, sequence, index+1) || findSequence(root->right, sequence, index+1);
    }
  public:
    static bool findPath(TreeNode *root, const vector<int> &sequence) {
      // TODO: Write your code here
      return findSequence(root, sequence, 0);
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
       << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}
