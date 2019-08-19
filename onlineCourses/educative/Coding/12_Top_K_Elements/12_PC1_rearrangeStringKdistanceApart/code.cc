// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5684793748488192

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/rearrange-string-k-distance-apart/

class RearrangeStringKDistanceApart {
   public:
     struct compareBig {
       bool operator()(pair<char, int> &p1, pair<char, int> &p2) {
         return p1.second < p2.second;
       }
     };

     static string reorganizeString(const string &str, int k) {
       // TODO: Write your code here
       if(k<2) return str;
       unordered_map<char, int> m;
       queue<pair<char, int>> q;
       pair<char, int> node;
       string result = "";
       priority_queue<pair<char, int>, vector<pair<char, int>>, compareBig> maxHeap;
       for(auto chr: str) {
         m[chr]++;
       }
       for(auto entry: m) {
         maxHeap.push(entry);
       }
       while(maxHeap.size()) {
         node = maxHeap.top();
         maxHeap.pop();
         result += node.first;
         node.second--;
         q.push(node);
         if(q.size() == k) {
           if(q.front().second > 0) {
             maxHeap.push(q.front());
           }
           q.pop();
         }
       }
       return str.size()==result.size() ? result : "";
     }
};

int main(int argc, char *argv[]) {
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("Programming", 3) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("mmpp", 2) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aab", 2) << endl;
  cout << "Reorganized string: " << RearrangeStringKDistanceApart::reorganizeString("aappa", 3)
       << endl;
}
