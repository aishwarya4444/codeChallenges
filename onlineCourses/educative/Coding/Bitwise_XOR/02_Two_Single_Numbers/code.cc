#include <iostream>
#include <vector>
using namespace std;

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
    // TODO: Write your code here

    int num1=0, num2=0, res=0, right=1;

    for(auto num: nums) {
      res = res^num;
    }cout<<res<<endl;

    while((right & res) == 0) {
      right = right<<1;
    }cout<<right<<endl;

    for(auto num: nums) {
      if(num & right) {
        num1 = num1^num;
      } else {
        num2 = num2^num;
      }
    }

    return vector<int>{num1, num2};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}
