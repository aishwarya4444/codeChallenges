/*
Given a set of "n" non-negative integers, and a value "sum",
determine if there is a subset of the given set with sum equal to given sum.

Input Format
1st Line: n sum 2nd Line: a1 a2……an (Array Values)

Constraints
1<= n <= 1000
1<= sum <= 10^5
1<= Ai <=10^4

Output Format
Yes, if sum exist
No, if sum does not exist

Sample Input
5 10
1 2 3 4 5

Sample Output
Yes
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
bool dp[2][100001];
int a[1001];

int main() {
    int n, S;
    int sum0, sum1;

    cin>>n>>S;

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    memset(dp, false, sizeof dp);

    for(int i=0; i<n; i++) {
        for(int c=0; c<=S; c++) {
            if(c==0) {
                dp[i%2][c] = true;
                continue;
            }
            dp[i%2][c] = dp[(i+1)%2][c];
            if(!dp[i%2][c] && c>=a[i]) {
                dp[i%2][c] = dp[(i+1)%2][c-a[i]];
            }
        }
    }

    if(dp[(n-1)%2][S]) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }

    return 0;
}
