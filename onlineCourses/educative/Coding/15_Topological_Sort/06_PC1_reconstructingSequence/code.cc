// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5792384199688192

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/sequence-reconstruction/

class SequenceReconstruction {
 public:
  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    // TODO: Write your code here
    unordered_map<int, vector<int> > graph;
    unordered_map<int, int> indegree;
    int i, parent, child;
    queue<int> source;
    vector<int> order;

    if(originalSeq.size() == 0) {
      return false;
    }

    // init graph
    for(auto seq : sequences) {
      for(i=0; i<seq.size(); i++) {
        indegree[seq[i]] = 0;
        graph[seq[i]] = vector<int>();
      }
    }

    // populate graph
    for(auto seq : sequences) {
      for(i=1; i<seq.size(); i++) {
        parent = seq[i-1];
        child = seq[i];
        indegree[child]++;
        graph[parent].push_back(child);
      }
    }

    // populate indegree
    for(auto entry: indegree) {
      if(entry.second == 0) {
        source.push(entry.first);
      }
    }

    // if we don't have rules for all seuqnces
    // we cannot construct a unique sequence
    if((int)indegree.size() != originalSeq.size()) {
      return false;
    }

    // bfs
    while(source.size()) {
      // if there are more than 1 sources we can't
      // construct a unique sequence
      if(source.size() > 1) {
        return false;
      }

      parent = source.front();
      source.pop();

      // check position of "parent" in "originalSeq"
      if(originalSeq[order.size()] != parent) {
        return false;
      }

      order.push_back(parent);

      auto children = graph[parent];
      for(auto child: children) {
        indegree[child]--;
        if(indegree[child] == 0) {
          source.push(child);
        }
      }
    }

    return order.size()==originalSeq.size();
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}
