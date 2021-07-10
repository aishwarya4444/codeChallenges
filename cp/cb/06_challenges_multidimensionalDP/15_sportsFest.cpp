/*
Prateek Bhaiya decided to organize a sports fest for students of Coding Blocks and he came to know
that Cricket, Football and Hockey are popular in the same order.
So, he laid down the following rules for the fest :

Only one match can be played in a single day.
Cricket can be played daily.
Football can't be played on two consecutive days.
There must be a gap of at least two days between two hockey matches.
Since Bhaiya is busy enjoying his Maggi, he wants you to write a program that can calculate the number of ways
the fest can be organised, given the number of days the fest is scheduled to be organised over.

Input Format
Single integer representing the duration of fest in number of days.

Constraints
1 <= Number of days <= 10^5

Output Format
Print a single integer, the total number of ways the fest can be organised in.
As the number of ways can be large, print the answer modulo 109+7.

Sample Input
2

Sample Output
7

Explanation
There are 7 number of ways : CC, FC, HC, CF, HF, FH, CH.
C denotes Cricket,
F denotes Football,
H denotes Hockey.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll dp[100001];
const int mod = 1e9+7;

ll solve(int i, bool football, bool hockey) {
    if(i>=n) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    ll ways = 0;
    ways = (ways + 1 + solve(i+1, true, true))%mod; // cricket
    if(football) ways = (ways + 1 + solve(i+1, false, true))%mod; // football
    if(hockey) ways = (ways + 1 + solve(i+1, true, false))%mod; // hockey

    return dp[i] = ways;
}

int main() {
    cin>>n;

    memset(dp, -1, sizeof dp);

    cout<<solve(0, true, true);

    return 0;
}
