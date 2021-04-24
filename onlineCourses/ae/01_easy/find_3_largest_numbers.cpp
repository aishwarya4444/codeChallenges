#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
	priority_queue<int, vector<int>, greater<int> > minHeap;
	vector<int> result;

	for(auto num: array) {
		minHeap.push(num);
		if(minHeap.size()>3) {
			minHeap.pop();
		}
	}

	while(minHeap.size()) {
		result.push_back(minHeap.top());
		minHeap.pop();
	}
  return result;
}
