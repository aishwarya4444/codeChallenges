// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5630239073894400

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
  public:
    struct compareLess {
      bool operator()(const pair<char, int> &p1, const pair<char, int> &p2) {
        return p1.second < p2.second;
      }
    };

    static string sortCharacterByFrequency(const string &str) {
      string sortedString = "";
      // TODO: Write your code here
      unordered_map<char, int> m;
      char c;
      priority_queue<pair<char,int>, vector<pair<char, int> >, compareLess> maxHeap;
      int n, N=str.size();
      for(n=0; n<N; n++) {
        m[str[n]]++;
      }
      for(auto entry : m) {
        maxHeap.push(entry);
      }
      while(maxHeap.size()) {
        c = maxHeap.top().first;
        n = maxHeap.top().second;
        maxHeap.pop();
        //while(n--) {
        //  sortedString = sortedString + c;
        //}
        sortedString += string(n, c);
      }
      return sortedString;
    }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
