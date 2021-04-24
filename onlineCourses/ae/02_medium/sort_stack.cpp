#include <vector>
using namespace std;

void insertInSortedOrder(vector<int> &stack, int value) {
	if(stack.size()==0 || stack.back()<=value) {
		stack.push_back(value);
		return;
	}

	int top = stack.back();
	stack.pop_back();

	insertInSortedOrder(stack, value);

	stack.push_back(top);
}

vector<int> sortStack(vector<int> &stack) {
  // Write your code here.
	if(stack.size() == 0) {
		return stack;
	}

	int top = stack.back();
	stack.pop_back();

	sortStack(stack);
	insertInSortedOrder(stack, top);

	return stack;
}
