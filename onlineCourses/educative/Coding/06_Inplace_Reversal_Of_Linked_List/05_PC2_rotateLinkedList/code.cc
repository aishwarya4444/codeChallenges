// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5461559008559104

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class RotateList {
 public:
  static ListNode *rotate(ListNode *head, int rotations) {
    // TODO: Write your code here
    ListNode *end1, *end2, *prev=NULL, *next=NULL, *curr=head;
    int k, n, N=0;

    // [] rotations=0
    if(!head || !head->next || !rotations) {
      return head;
    }

    // find length of list
    while(curr) {
      curr = curr->next;
      N++;
    }
    k = rotations%N;

    // [1,2] rotations=2
    if(!rotations) {
      return head;
    }

    curr = head;
    end1 = head;

    // rotate N-k nodes
    for(n=0; n<N-k; n++) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    head = prev;
    end2 = curr;

    // rotate k nodes
    for(n=0; n<k; n++) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    end1->next = prev;
    end2->next = NULL;

    // rotate whole list
    prev = NULL;
    curr = head;
    while(curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    head = prev;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  ListNode *result = RotateList::rotate(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
