// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6610306698575872

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
  public:
    static string findOrder(const vector<string> &words) {
      string sortedOrder;
      // TODO: Write your code here
      unordered_map<char, vector<char> > graph;
      unordered_map<char, int> inDegree;
      queue<char> sources;
      vector<char> children;
      string w1, w2;
      char alphabet;
      int i, j;

      // initialise
      for(auto word: words) {
        for(auto letter: word) {
          inDegree[letter]=0;
          graph[letter]=vector<char>();
        }
      }

      // populate
      for(i=0; i<words.size()-1; i++) {
        w1 = words[i];
        w2 = words[i+1];
        for(j=0; j<min(w1.size(), w2.size()); j++) {
          if(w1[j]!=w2[j]) {
            inDegree[w2[j]]++;
            graph[w1[j]].push_back(w2[j]);
            break;
          }
        }
      }

      // find sources
      for(auto entry: inDegree) {
        if(entry.second==0) {
          sources.push(entry.first);
        }
      }

      // order
      while(sources.size()) {
        alphabet = sources.front();
        sources.pop();
        sortedOrder+=alphabet;
        children = graph[alphabet];
        for(auto child: children) {
          inDegree[child]--;
          if(inDegree[child]==0) {
            sources.push(child);
          }
        }
      }

      return sortedOrder.size() ? sortedOrder : "";
    }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
