/*

https://www.codechef.com/JULY19B/problems/CIRMERGE
similar : https://codeforces.com/problemset/problem/1372/D

my solution less memory / more time (used inline function to avoid TLE) = https://www.codechef.com/viewsolution/48517184
my solution more memory / less time = https://www.codechef.com/viewsolution/48517610
refer = https://www.codechef.com/viewsolution/25308774

N integers A1,A2,…,AN are placed in a circle in such a way that
for each valid i, Ai and Ai+1 are adjacent, and A1 and AN are also adjacent.

We want to repeat the following operation exactly N−1 times (until only one number remains):
[1] Select two adjacent numbers. Let's denote them by a and b.
[2] Score a+b penalty points.
[3] Erase both a and b from the circle and insert a+b in the space between them.

What is the minimum number of penalty points we can score?

Input Format
The first line contains a single integer N. The second line contains N space-separated integers a1,a2,…,aN.

Constraints
2 ≤ N ≤ 400
1 ≤ ai ≤ 10^9 for each valid i

Output Format
Print a single line containing one integer — the minimum number of penalty points.

Sample Input

3
10 10 1

Sample Output
32

Explanation
[10,10,1]→[10,11] , penalty: 11
[10,11]→[21], penalty: 21
Total penalty: 11+21=32
*/


/* **************************** */
/* SOLUTION WITH LESS DP MEMORY */
/* **************************** */
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int a[401];
ll dp[401][401];
ll sum[401][401];

ll solve(int i, int j) {
    // if(i>=j) {
    if(i==j) {
        return dp[i][j] = 0;
    }

    if((i+1)%n==j) {
        return dp[i][j] = a[i]+a[j];
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    ll res = LLONG_MAX;
    // for(int k=i; k<j; k++) {
    for(int k=i; k!=j; k=(k+1)%n) {
        // res = min(res, solve(i,k)+solve(k+1,j)+csum(i,k)+csum(k+1,j));
        res = min(res, solve(i,k)+solve((k+1)%n,j)+sum[i][k]+sum[(k+1)%n][j]);
    }

    return dp[i][j] = res;
}

int main() {

    int t=1;

    // cin>>t;
    while(t--) {
        ll ans = LLONG_MAX;
        cin>>n;

        memset(dp, -1, sizeof dp);
        memset(sum, 0, sizeof sum);

        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        for(int r=0; r<n; r++) {
            sum[r][r] = a[r];
            for(int c=(r+1)%n; c!=r; c=(c+1)%n) {
                sum[r][c] = a[c] + sum[r][(c-1+n)%n];
            }
        }

        for(int s=0; s<n; s++) {
            int e = (s+n-1)%n;
            ans = min(ans, solve(s,e));
        }
        cout<<ans<<'\n';
    }

    return 0;
}


/* **************************** */
/* SOLUTION WITH MORE DP MEMORY */
/* **************************** */
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> a;
ll dp[802][802];
ll sum[802];

ll csum(int l, int r) {
    return sum[r]-sum[l-1];
}

ll solve(int i, int j) {
    if(i>=j) {
        return 0;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    ll res = LLONG_MAX;
    for(int k=i; k<j; k++) {
        res = min(res, solve(i,k)+solve(k+1,j)+csum(i,k)+csum(k+1,j));
    }

    return dp[i][j] = res;
}

void prepareSum(int s) {
    memset(sum, 0, sizeof sum);
    for(int i=0; i<n; i++) {
        sum[i+s] = a[i] + sum[i+s-1];
    }
}

int main() {
    int num, t=1;
    // cin>>t;
    while(t--) {
        ll ans = LLONG_MAX;

        memset(dp, -1, sizeof dp);
        a.clear();

        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>num;
            a.push_back(num);
        }

        for(int s=0; s<n; s++) {
            int e = s+n-1;
            prepareSum(s);
            ans = min(ans, solve(s,e));
            a.push_back(a[0]);
            a.erase(a.begin());
        }
        cout<<ans<<endl;

    }
    return 0;
}
