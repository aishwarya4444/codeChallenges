/*
https://codeforces.com/problemset/problem/895/C
https://codeforces.com/blog/entry/56028

Kartik's Solution
https://ideone.com/5ZoWWv

Given a array of size N.
find the number of subsets such that product of all its elements is a perfect square.
Since, answer could be very large , output it modulo (10^9+7).

Input Format
The first line contains N number, followed by N numbers in the next line.

Constraints
n<=10^5
A[i]<=70

Output Format
Output a single number denoting the number of subsets

Sample Input
4
1 1 1 1

Sample Output
15
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int a[71];
int pow2[100001];
int dp[71][1<<19];
const int mod = 1e9+7;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int solve(int i, int mask) {
    if(i==71) {
        return mask==0 ? 1 : 0;
    }

    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }

    if(a[i] == 0) {
        return dp[i][mask] = solve(i+1, mask);
    }

    int ways = pow2[a[i]-1];
    ll ans = ( 1LL * ways * solve(i+1, mask) ) % mod;

    int num = i;
    int tmp_mask = mask;
    for(int p=0; p<primes.size(); ) {
        if(num && num%primes[p] == 0) {
            num /= primes[p];
            tmp_mask = (tmp_mask^(1<<p));
        } else {
            p++;
        }
    }
    ans = ( ans + ( 1LL * ways * solve(i+1, tmp_mask) ) % mod ) % mod;
    /*********

    I made 1 mistake.
    I did not multiply by 1LL.
    So, ans was wrong.

    PLEASE NOTE
    It is important to typecast to upper range and then take modulus.

    *********/

    return dp[i][mask] = ans;
}

int main() {
    int num;

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>num;
        a[num]++;
    }

    pow2[0] = 1;
    for(int i=1; i<=100000; i++) {
        pow2[i] = (2*pow2[i-1]) % mod;
    }

    memset(dp, -1, sizeof dp);
    cout<<solve(1, 0)-1;

    return 0;
}
