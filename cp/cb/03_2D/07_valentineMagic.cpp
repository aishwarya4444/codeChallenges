/*
It's Valentine's Day in Russia today.
Aas we all know number of girls in Russia is more than number of boys.
Hence boys have an extra advantage while choosing girl for the valentine evening.
Each boy has certain number of chocolates and each girl has certain number of candies.
Now you being the anchor of evening wants to pair all the boys with girls such that
the sum of absolute difference between boy's chocolate and girl's candy in a pair is minimized.
Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia.

Input Format
The first line consists of two integers N and M.
Then follow N integers in second line.
Then follow M integers in third line. M >= N

Constraints
1 <= N <= 5000
1 <= M <= 5000
M >= N
1 <= chocolates <= 1000000
1 <= candies <= 1000000

Output Format
The only line which consists of required sum of absolute differences.

Sample Input
2 5
4 5
1 2 3 4 5

Sample Output
0

Explanation
we can pair boy numbered 1 with girl numbered 4 and boy numbered 2 with girl numbered 5
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e11;
vector<int> b, g;
int n, m;
ll dp[5000][5000];

ll solve(int i, int j) {
    if(i==n) {
        // all boys are paired
        return 0;
    }
    if(j==m) {
        // all girls are paired
        // boys are left
        // we did not want this
        return INF;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    ll op1 = abs(b[i]-g[j]) + solve(i+1, j+1);
    ll op2 = solve(i, j+1);

    return dp[i][j] = min(op1, op2);
}

int main() {
    int val;

    cin>>n>>m;

    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++) {
        cin>>val;
        b.push_back(val);
    }

    for(int i=1; i<=m; i++) {
        cin>>val;
        g.push_back(val);
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    cout<<solve(0, 0);

    return 0;

}
