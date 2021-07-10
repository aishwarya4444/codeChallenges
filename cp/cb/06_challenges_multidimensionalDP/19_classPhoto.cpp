/*

https://www.codechef.com/problems/RAMLEELA

editorial solution : https://www.codechef.com/viewsolution/39045322
more optimised solution : https://www.codechef.com/viewsolution/12050994

There are "b" boys and "g" girls in a class. Today is the day of their class photograph.
The photographer loves having different arrangements for a photograph.
He decides that the photo would look awesome if there are atmost n1 adjacent boys and atmost adjacent n2 girls lined up together.
If there are more than n1 boys, or more than n2 girls standing together(successively one after another),
then the photograph will not look awesome.

So, find the number of ways in which the photographer can arrange b boys and g girls so that the photograph looks awesome.

Input Format
One line containing four integers - b , g , n1 , n2 .

Constraints
1<=b,g<=1000
1 ≤ n1,n2 ≤ 20

Output Format
Output a single i.e the no.of arrangements modulo 10^9 + 7

Sample Input
1 2 5 1

Sample Output
1

Explanation
Example case 1. “GBG” is the only awesome arrangement.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int B, G, n1, n2;
int dp[1001][1001][21][2];
const int mod = 1e9+7;

// boy  = state = 0
// girl = state = 1
int solve(int b, int g, int n, int state) {
    if(dp[b][g][n][state] != -1) {
        return dp[b][g][n][state];
    }

    if(b+g==B+G) {
        return 1;
    }


    ll ways = 0;
    if(b<B) {
        if(state==0 && n<n1) {
            ways = (ways + solve(b+1, g, n+1, 0))%mod;
        }
        if(state==1) {
            ways = (ways + solve(b+1, g, 1, 0))%mod;
        }
    }

    if(g<G) {
        if(state==0) {
            ways = (ways + solve(b, g+1, 1, 1))%mod;
        }
        if(state==1 && n<n2) {
            ways = (ways + solve(b, g+1, n+1, 1))%mod;
        }
    }

    return dp[b][g][n][state] = ways;
}

int main() {
    cin>>B>>G>>n1>>n2;

    memset(dp, -1, sizeof dp);

    cout<<solve(0, 0, 0, 0);

    return 0;
}

/*
// Memory Limit Exceeded + Wrong Answer
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int B, G, n1, n2;
// Wrong Answer
ll dp[101][101][21][21];

// Memory Limit Exceeded
//ll dp[1001][1001][21][21];
const int mod = 1e9+7;

ll solve(int b, int g, int nb, int ng) {
    if(b>B || g>G) {
        return 0;
    }
    if(b+g==B+G) {
        return 1;
    }

    if(dp[b][g][nb][ng] != -1) {
        return dp[b][g][nb][ng];
    }

    ll ways = 0;
    if(nb<n1) {
        ways = (ways + solve(b+1, g, nb+1, 0))%mod;
    }
    if(ng<n2) {
        ways = (ways + solve(b, g+1, 0, ng+1))%mod;
    }

    return dp[b][g][nb][ng] = ways;
}

int main() {
    cin>>B>>G>>n1>>n2;

    memset(dp, -1, sizeof dp);

    cout<<solve(0, 0, 0, 0);

    return 0;
}
*/