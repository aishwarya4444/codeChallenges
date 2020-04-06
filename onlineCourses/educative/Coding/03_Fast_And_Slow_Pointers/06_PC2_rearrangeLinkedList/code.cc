// https://www.educative.io/courses/grokking-the-coding-interview/YQJ4mr7yOrW

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

// https://leetcode.com/problems/reorder-list/

class RearrangeList {
 public:
  static ListNode *reverseList(ListNode *head) {
    ListNode *prev=NULL, *next=NULL, *curr=head;
    if(!head || !head->next) {
      return head;
    }
    while(curr) {
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    return prev;
  }
  static void reorder(ListNode *head) {
    // TODO: Write your code here
    ListNode *p1=head, *p2=head, *tmp;
    if(!head || !head->next) {
      return;
    }
    while(p2 && p2->next) {
      p1=p1->next;
      p2=p2->next->next;
    }
    p2=reverseList(p1);
    p1=head;
    while(p1 && p2) {
      tmp=p1->next;
      p1->next=p2;
      p1=tmp;
      tmp=p2->next;
      p2->next=p1;
      p2=tmp;
    }
    if(p1) {
      p1->next=NULL;
    }
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  head->next->next->next->next->next = new ListNode(12);
  RearrangeList::reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}
