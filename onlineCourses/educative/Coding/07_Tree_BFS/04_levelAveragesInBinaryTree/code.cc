// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5632908932939776

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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;
    // TODO: Write your code here
    queue<TreeNode*> q;
    double sum;
    int i,n;
    if(root) {
      q.push(root);
    }
    while(q.size()) {
      n=q.size();
      sum=0;
      for(i=0;i<n;i++) {
        root=q.front();
        q.pop();
        sum+=root->val;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
      }
      sum/=n;
      result.push_back(sum);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
