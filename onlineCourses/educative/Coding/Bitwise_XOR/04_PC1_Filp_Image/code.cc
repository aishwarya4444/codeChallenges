#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/flipping-an-image/

class Solution {
  public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> A) {
      //TODO: Write your code here
      int n1, n2, r, c, R=A.size(), C=R?A[0].size():0;

        for(r=0; r<R; r++) {
            for(c=0; c<=(C-1)/2; c++) {
                n1 = 1^A[r][c];
                n2 = 1^A[r][C-1-c];

                A[r][c] = n2;
                A[r][C-1-c] = n1;
            }
        }

        return A;
    }

    static void print(const vector<vector<int>> arr) {
      for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  Solution::print(Solution::flipAndInvertImage(arr));
  cout << endl;

  vector<vector<int>> arr2 = vector<vector<int>>{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
  Solution::print(Solution::flipAndInvertImage(arr2));
}