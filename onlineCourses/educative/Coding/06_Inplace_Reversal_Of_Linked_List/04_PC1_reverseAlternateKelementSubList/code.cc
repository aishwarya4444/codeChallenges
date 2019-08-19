// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5649553887854592

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

class ReverseAlternatingKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    ListNode *current=head, *prev=NULL, *next=NULL, *end1, *end2;
    int i;

    while(current) {
      // reverse k nodes
      end1 = prev;
      end2 = current;
      for(i=0; i<k && current; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }

      if(end1) {
        end1->next = prev;
      } else {
        head = prev;
      }
      end2->next = current;
      prev = end2;

      // skip k nodes
      for(i=0; i<k && current; i++) {
        prev = current;
        current = current->next;
      }
    }

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
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseAlternatingKElements::reverse(head, 2);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
