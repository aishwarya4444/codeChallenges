// https://www.educative.io/courses/grokking-the-coding-interview/39q3ZWq27jM

using namespace std;

#include <iostream>

class HappyNumber {
 public:
  static int findSum(int num) {
    int sum=0;
    while(num) {
      sum = sum+(num%10)*(num%10);
      num/=10;
    }
    return sum;
  }

  static bool find(int num) {
    // TODO: Write your code here
    int slow = num, fast = num;
    while (slow && num) {
      slow = findSum(slow);
      fast = findSum(findSum(fast));
      if(slow==fast) {
        return slow==1;
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
