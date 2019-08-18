// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5720758194012160

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    // TODO: Write your code here
    vector<int> perm, newPerm;
    queue<vector<int> > q;
    q.push(perm);
    int i, j, N;
    for(auto num: nums) {
      N = q.size();
      for(i=0; i<N; i++) {
        perm = q.front();
        q.pop();
        for(j=0; j<=perm.size(); j++) {
          newPerm = perm;
          newPerm.insert(newPerm.begin()+j, num);
          if(newPerm.size() == nums.size()) {
            result.push_back(newPerm);
          } else {
            q.push(newPerm);
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
