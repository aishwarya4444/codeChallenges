/*
same as ques 19
https://leetcode.com/problems/delete-and-earn/
https://codeforces.com/problemset/problem/455/A
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000007;
int a[100001];
int dp[100001];

int main() {
    int n, num, maxNum=0;

    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>num;
        maxNum = max(maxNum, num);
        a[num]++;
    }

    dp[0] = 0;
    dp[1] = a[1];
    for(int i=2; i<=maxNum; i++) {
        dp[i] = max(i*a[i]+dp[i-2], dp[i-1]);
    }

    cout<<dp[maxNum];

    return 0;
}

/*
// top down soln TLE
class Solution {
private:
    int n[10001];
    int dp[1001][1001];

public:
    int solve(int l, int r) {
        if(l==r) return l*n[l];
        if(l>r) return 0;

        if(dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0;
        for(int i=l; i<=r; i++) {
            if(n[i] == 0) continue;
            ans = max(ans, solve(l, i-2) + i*n[i] + solve(i+2, r));
            // cout<<i<<" : "<<solve(l, i-2)<<' '<<ans<<' '<<solve(i+2, r)<<endl;
        }

        return dp[l][r] = ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        int mx = 0, mn = nums[0];

        memset(n, 0, sizeof n);
        memset(dp, -1, sizeof dp);

        for(int num: nums) {
            n[num]++;
            mx = max(mx, num);
            mn = min(mn, num);
        }

        return solve (mn, mx);

    }
};
*/
