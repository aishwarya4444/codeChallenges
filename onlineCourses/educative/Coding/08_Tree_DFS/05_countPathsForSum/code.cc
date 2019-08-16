// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5658962204557312

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

class CountAllPathSum {
  private:
   static void countHelp(TreeNode *root, int &S, int &paths, vector<int> &path) {
     if(!root) return;
     path.push_back(root->val);
     countHelp(root->left, S, paths, path);
     countHelp(root->right, S, paths, path);
     int i, sum = 0;
     for(i=path.size()-1; i>=0; i--) {
       sum += path[i];
       if(sum == S) {
         paths++;
       }
     }
     path.pop_back();
   }
  public:
    static int countPaths(TreeNode *root, int S) {
      // TODO: Write your code here
      int paths = 0;
      vector<int> path;
      countHelp(root, S, paths, path);
      return paths;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}
