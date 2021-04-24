#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  // Write your code here.
	LinkedList *p1=head, *p2=head;

	while(p1 && p2) {
		p1 = p1->next;
		p2 = p2->next ? p2->next->next : p2->next;
		if(p1 == p2) {
			break;
		}
	}

	if(p1!=p2) {
		return NULL;
	}

	p1 = head;
	while(p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

  return p1;
}
