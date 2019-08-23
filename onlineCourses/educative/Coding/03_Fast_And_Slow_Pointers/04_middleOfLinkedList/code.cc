// https://www.educative.io/courses/grokking-the-coding-interview/3j5GD3EQMGM

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

// https://leetcode.com/problems/middle-of-the-linked-list/

class MiddleOfLinkedList {
 public:
  static ListNode *findMiddle(ListNode *head) {
    // TODO: Write your code here
    if(!head) return NULL;
    if(!head->next) return head;
    ListNode *p1=head, *p2=head;
    while(p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return p1;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next = new ListNode(6);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;

  head->next->next->next->next->next->next = new ListNode(7);
  cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->value << endl;
}
