/*
Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets.
He has to find whether if the sum of any of the non-empty subsets of the set A is zero.

Input Format
The first line contains an integer T, which is the total number of test cases.
T test cases follow.
Each test case consists of two lines.
The first line consists of a single integer N, which is the number of elements present in the set A.
The second line contains N space separated integers denoting the elements of the set A.

Constraints
1 ≤ T ≤10
1 ≤ N ≤ 4
-10^5 ≤ A[i] ≤ 10^5

Output Format
Print the answer for each testcase in a new line.
If the sum of any of the subset is zero, then print “Yes” (without quotes) else print “No”(without quotes).

Sample Input
1
4
1 3 2 -3

Sample Output
Yes

Explanation
The sum of the subset {3,-3} is zero.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n;
int a[4];

bool solve(int i, int sum, int count) {
    if(count && sum==0) {
        return true;
    }
    if(i==n) {
        return false;
    }

    return solve(i+1, sum+a[i], count+1) || solve(i+1, sum, count);
}

int main() {
    int t;

    cin>>t;

    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        if(solve(0, 0, 0)) {
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }

    return 0;
}
