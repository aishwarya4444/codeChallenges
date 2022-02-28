/*

https://www.codechef.com/submit/COINS

Tughlaq introduces a strange monetary system.
He introduces copper coins and each coin has a number written on it.
A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4.
A coin can also be sold for gold.
One can get as much grams of gold as the number written on the coin.
You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format
The input file contains a single integer n, the number on the coin.

Constraints
0 <= n <= 1 000 000 000

Output Format
Print the maximum weight of gold you can get.

Sample Input
12
Sample Output
13
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;
// we use map because 10^9 memory is too much
// using less memory will give SIGSEV
// using more gives compile error .. but runs locally if we do not memset(dp, -1, sizeof dp) as 10^9 ops are not done

ll solve(ll n) {
    if(n<=8) { // n<2 also works
        return n;
    }

    if(mp.count(n)) {
        return mp[n];
    }

    ll ans = max(n, solve(n/2)+solve(n/3)+solve(n/4));

    return mp[n] = ans;
}

int main() {
    ll n;
    while(cin>>n)
        cout<<solve(n)<<endl;
}

// ll dp[1000000001];

// int main() {
//     ll n;

//     cin>>n;

//     dp[1] = 1;
//     for(ll i=2; i<=n; i++) {
//         dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4], i);
//     }

//     cout<<dp[n];

//     return 0;
// }
