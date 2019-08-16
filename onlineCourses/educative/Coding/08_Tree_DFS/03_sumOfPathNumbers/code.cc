// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5675214360805376

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

class SumOfPathNumbers {
  private:
    static void findSum(TreeNode *root, int num, int &sum) {
      if(!root)return;
      num = num*10 + root->val;
      if(!root->left && !root->right) {
        sum += num;
      } else {
        findSum(root->left, num, sum);
        findSum(root->right, num, sum);
      }
    }
  public:
    static int findSumOfPathNumbers(TreeNode *root) {
      int totalPathsSum = 0;
      // TODO: Write your code here
      int num=0;
      findSum(root, num, totalPathsSum);
      return totalPathsSum;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
