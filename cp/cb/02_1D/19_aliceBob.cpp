/*
same as ques 13
https://leetcode.com/problems/delete-and-earn/
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