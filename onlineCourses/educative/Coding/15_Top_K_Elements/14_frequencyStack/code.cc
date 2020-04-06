// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4868698198245376

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencyStack {
 public:
  struct freqNode {
    int num;
    int seq;
    int freq;
    freqNode(int n, int s, int f) {
      num = n;
      seq = s;
      freq = f;
    }
  };

  struct compareNode {
    bool operator()(freqNode &n1, freqNode &n2) {
      if(n1.freq == n2.freq) {
        return n1.seq < n2.seq;
      }
      return n1.freq < n2.freq;
    }
  };

  unordered_map<int, int> m;
  priority_queue<freqNode, vector<freqNode>, compareNode> maxHeap;

  int sequence = 1;

  virtual void push(int num) {
    // TODO: Write your code here
    m[num]++;
    maxHeap.push({num, sequence++, m[num]});
  }

  virtual int pop() {
    // TODO: Write your code here
    if(maxHeap.empty()) {
      return -1;
    }
    int num = maxHeap.top().num;
    maxHeap.pop();
    m[num]--;
    return num;
  }
};

int main(int argc, char *argv[]) {
  FrequencyStack frequencyStack;
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(3);
  frequencyStack.push(2);
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(5);
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
}
