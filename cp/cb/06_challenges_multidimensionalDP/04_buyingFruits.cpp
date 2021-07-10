/*
Prateek went to purchase fruits mainly apples, mangoes and oranges.
There are N different fruit sellers in a line.
Each fruit seller sells all three fruit items, but at different prices.
Prateek, obsessed by his nature to spend optimally, decided not to purchase same fruit from adjacent shops.
Also, Prateek will purchase exactly one type of fruit item (only 1kg) from one shop.
Prateek wishes to spend minimum money buying fruits using this strategy.
Help Prateek determine the minimum money he will spend.
If he becomes happy, he may offer you discount on your favorite course in Coding Blocks ;).
All the best!

Input Format
First line indicates number of test cases T.
Each test case in its first line contains N denoting the number of fruit sellers in Fruit Market.
Then each of next N lines contains three space separated integers denoting cost of apples, mangoes
and oranges per kg with that particular fruit seller.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
Cost of each fruit(apples/mangoes/oranges) per kg does not exceed 10^4

Output Format
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Sample Input
1
3
1 50 50
50 50 50
1 50 50

Sample Output
52

Explanation
There are two ways, each one gives 52 as minimum cost. One way is buy apples from first shop,
mangoes from second shop and apples from third shop or he can buy apples from first shop,
oranges from second shop and apples from third shop.

Both ways , cost comes up to 1 + 50 + 1 = 52
*/

// solution 1
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[100001][3];
int n, k;
int f[100001][3];

int solve(int i, int leave) {
    if(i>n) {
        return 0;
    }

    if(dp[i][leave] != -1) {
        return dp[i][leave];
    }

    int ans = INT_MAX;

    for(int k=0; k<3; k++) {
        if(k==leave) continue;
        ans = min(ans, f[i][k]+solve(i+1, k));
    }

    return dp[i][leave] = ans;
}

int main() {
    int t;

    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp, -1, sizeof dp);
        for(int i=1; i<=n; i++) {
            cin>>f[i][0]>>f[i][1]>>f[i][2];
        }
        dp[0][0] = f[1][0] + solve(2,0);
        dp[0][1] = f[1][1] + solve(2,1);
        dp[0][2] = f[1][2] + solve(2,2);
        cout<<min({dp[0][0], dp[0][1], dp[0][2]})<<endl;
    }

    return 0;
}

// solution 2
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[100001][3];
int n, k;
int f[100001][3];

int solve(int i, int leave) {
    if(i==n) {
        return 0;
    }

    if(dp[i][leave] != -1) {
        return dp[i][leave];
    }

    int ans = INT_MAX;

    for(int k=0; k<3; k++) {
        if(k==leave) continue;
        ans = min(ans, f[i][k]+solve(i+1, k));
    }

    return dp[i][leave] = ans;
}

int main() {
    int t;

    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++) {
            cin>>f[i][0]>>f[i][1]>>f[i][2];
        }
        cout<<solve(0,3)<<endl;
    }

    return 0;
}
