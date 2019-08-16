// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5722467590995968

using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // tree traversal using 'next' pointer
  virtual void printTree() {
    TreeNode *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current != nullptr) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
   // TODO: Write your code here
    TreeNode *prev=NULL;
    queue<TreeNode*> q;
    int n;
    if(root) {
      q.push(root);
    }
    while(q.size()) {
      n=q.size();
      while(n--) {
        root=q.front();
        q.pop();
        if(prev) {
          prev->next=root;
        }
        prev=root;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ConnectAllSiblings::connect(root);
  root->printTree();
}
