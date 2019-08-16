// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5742636757417984

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

class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
    // TODO: Write your code here
   queue<TreeNode*> q;
   TreeNode *previous=NULL;
   if(root) {
     q.push(root);
   }
   while(q.size()) {
     root=q.front();
     q.pop();
     if(previous) {
       return root;
     }
     if(root->val==key) {
       previous=root;
     }
     if(root->left)q.push(root->left);
     if(root->right)q.push(root->right);
   }
   return nullptr;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
}
