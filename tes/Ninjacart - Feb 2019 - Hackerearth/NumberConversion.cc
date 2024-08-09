#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long solve (vector<int> &A, vector<int> &P, vector<int> &Q, long long left, long long right) {
   long long currLeft, currRight;
   int i, count=0;
   bool found=false;
   while(left<=right){
     found=true;
     for(i=0;i<A.size();i++) {
       currLeft=A[i]-Q[i];
       currRight=A[i]+Q[i];
       if(currLeft<=left && left<=currRight) {
         // ok no problem .. keep going
       } else {
         found=false;
         break;
       }
     }
     if(found) {
       count++;
     }
     left++;
   }
   return count;
}

int main() {
  int i, n, num, T;
  vector<int> A, P, Q;
  long long left, right;
  cin >> T;
  for(int t_i=0; t_i<T; t_i++)
  {
    A.clear();
    P.clear();
    Q.clear();
    cin >> n;
    for(i=0; i<n; i++)
    {
      cin >> num;
      A.push_back(num);
    }
    for(i=0; i<n; i++)
    {
      cin >> num;
      P.push_back(num);
    }
    for(i=0; i<n; i++)
    {
      cin >> num;
      Q.push_back(num);
      if(i==0) {
        left=A[0]-Q[0];
        right=A[0]+P[0];
      } else {
        left= (left>A[i]-Q[i]) ? left : A[i]-Q[i];
        right= (right<A[i]+P[i]) ? right : A[i]+P[i];
      }
    }
    cout << solve(A, P, Q, left, right) << "\n";
  }
  return 0;
}