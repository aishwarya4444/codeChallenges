#include <iostream>
#include <vector>
using namespace std;

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      // TODO: Write your code here
      int res=0;
      for(auto num: arr) {
        res = res^num;
      }
      return res;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}