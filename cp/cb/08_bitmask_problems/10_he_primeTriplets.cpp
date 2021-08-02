/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/mehta-and-the-tricky-triplets/
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/mehta-and-the-tricky-triplets/editorial/
https://ide.codingblocks.com/s/211121

Given an array A of n integers.
Find number of triplets (i,j,k) where i<j<k such that there is atleast one prime digit which is common to each number.

Input Format
The first line contains N integers followed by the number of elements

Constraints
N<=10^5
Ai<=10^18.

Output Format
Output the number of triplets

Sample Input
5
21
22
23
24
25

Sample Output
10
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int a[100001];
ll dp[100001][4][1<<4];
const int mod = 1e9+7;
unordered_map<int, int> primes = {{2,0}, {3,1}, {5,2}, {7,3}};

ll solve(int i, int t, int mask) {
    if(i==n) {
        if(t==3 && mask) return 1;
        return 0;
    }

    if(dp[i][t][mask] != -1) {
        return dp[i][t][mask];
    }

    ll ans = solve(i+1, t, mask);

    if(t<3) ans += solve(i+1, t+1, mask & a[i]);

    return dp[i][t][mask] = ans;
}

int prepareMask(ll num) {
    int mask = 0;

    while(num) {
        if(primes.find(num%10) != primes.end()) {
            mask = mask | (1<<primes[num%10]);
        }
        num /= 10;
    }

    return mask;
}

int main() {
    ll num;

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>num;
        a[i] = prepareMask(num);
    }

    memset(dp, -1, sizeof dp);
    cout<<solve(0, 0, ((1<<4)-1));

    return 0;
}
