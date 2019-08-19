// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5724822843686912

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
  public:
    struct compareMax {
      bool operator()(pair<char, int> &p1, pair<char, int> &p2) {
        return p1.second < p2.second;
      }
    };
    static string rearrangeString(const string &str) {
      // TODO: Write your code here
      unordered_map<char, int> m;
      priority_queue<pair<char, int>, vector<pair<char, int>>, compareMax> maxHeap;
      pair<char, int> prev(0, 0), curr;
      string result = "";

      for(auto chr: str) {
        m[chr]++;
      }
      for(auto entry: m) {
        maxHeap.push(entry);
      }
      while(maxHeap.size()) {
        curr = maxHeap.top();
        maxHeap.pop();
        curr.second--;

        if(prev.second > 0) {
          maxHeap.push(prev);
        }
        result += curr.first;
        prev = curr;
      }
      return result.size()==str.size() ? result : "";
    }
};

int main(int argc, char *argv[]) {
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
