// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6265122324480000

#include <iostream>
#include <string>
using namespace std;

class BackspaceCompare {
 public:
  static int getValidCharIndex(const string &str, int index) {
    int backspace = 0;
    while(index>=0) {
      if(str[index] == '#') {
        backspace++;
      } else if(backspace > 0) {
        backspace--;
      } else {
        break;
      }
      index--;
    }
    return index;
  }

  static bool compare(const string &str1, const string &str2) {
    int i1 = str1.size()-1, i2 = str2.size()-1;
    int skip1, skip2;
    while(i1>=0 || i2>=0) {
      skip1 = getValidCharIndex(str1, i1);
      skip2 = getValidCharIndex(str2, i2);

      if(skip1<0 && skip2<0) {
        return true;
      }

      if(skip1<0 || skip2<0) {
        return false;
      }

      if(str1[skip1] != str2[skip2]) {
        return false;
      }

      i1 = skip1-1;
      i2 = skip2-1;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}
