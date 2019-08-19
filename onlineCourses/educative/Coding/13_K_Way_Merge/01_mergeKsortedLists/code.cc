// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4611799594827776

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
  public:
    struct compare {
      bool operator()(ListNode *l1, ListNode *l2) {
        return l1->value > l2->value;
      }
    };
    static ListNode *merge(const vector<ListNode *> &lists) {
      ListNode *resultHead = nullptr;
      // TODO: Write your code here
      priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
      ListNode *resultTail = NULL, *tempNode;
      for(auto list: lists) {
        minHeap.push(list);
      }
      while(minHeap.size()) {
        tempNode = minHeap.top();
        minHeap.pop();
        if(tempNode->next) {
          minHeap.push(tempNode->next);
        }
        if(!resultHead) {
          resultHead = resultTail = tempNode;
        } else {
          resultTail->next = tempNode;
          resultTail = resultTail->next;
        }
      }
      return resultHead;
    }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
