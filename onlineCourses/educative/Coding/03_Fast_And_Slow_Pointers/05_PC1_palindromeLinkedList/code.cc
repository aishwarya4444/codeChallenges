// https://www.educative.io/courses/grokking-the-coding-interview/B1PzmqOKDLQ

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

// https://leetcode.com/problems/palindrome-linked-list/

class PalindromicLinkedList {
 public:
  static ListNode* reverseList(ListNode *head) {
    ListNode *prev=NULL, *next=NULL, *curr=head;
    if(!head || !head->next) {
      return head;
    }
    while(curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    return head;
  }
  static bool isPalindrome(ListNode *head) {
    // TODO: Write your code here
    if(!head || !head->next) return true;
    ListNode *p1=head, *p2=head, *rev;
    bool isPalindrome = true;
    while(p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    p1 = reverseList(p1);
    rev = p1;
    while(rev && head) {
      if(rev->value != head->value) {
        isPalindrome = false;
        break;
      }
      rev = rev->next;
      head = head->next;
    }
    reverseList(p1);
    return isPalindrome;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}
