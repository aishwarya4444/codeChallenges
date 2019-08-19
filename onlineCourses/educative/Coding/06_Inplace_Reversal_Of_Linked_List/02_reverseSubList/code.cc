// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5714632037629952

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

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    // TODO: Write your code here
    ListNode *current=head, *next=NULL, *prev=NULL, *end1, *end2;
    int i=1;
    if(p>=q || !head || !head->next) {
      return head;
    }
    while(i<p && current) {
      i++;
      prev = current;
      current = current->next;
    }
    end1 = prev;
    end2 = current;
    prev = NULL;
    while(p<=q && current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
      p++;
    }
    if(end1) {
      end1->next = prev;
    } else {
      head = prev;
    }
    end2->next = current;
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
