// https://www.educative.io/courses/grokking-the-coding-interview/g2w6QPBA2Nk

using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    // TODO: Write your code here
    int N=letters.size(), l=0, m, r=N-1;
    if(key<letters[0] || key>letters[N-1]) {
      return letters[0];
    }
    while(l<=r) {
      m = l + (r-l)/2;
      if(key<letters[m]) {
        r=m-1;
      } else { // if (key >= letters[mid]) {
        l=m+1;
      }
    }
    return letters[l%N];
  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}
