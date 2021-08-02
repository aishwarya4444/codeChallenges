/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/string-matching-google-3dc355a5/

Problem
Given a string X formed out of single digit numbers from 0-9, you are given a set of digits S
and you need to count total substring of string X that contains all the digits in the set S.
Input
First line contains a string as input.
Next line contains a number n as input denoting size of set S.
Next line contains n space separated integers that denote the distinct integers in the set S.

Output
In the output you have to give total count of substrings of the string X such that they contain all the digits in the set S

Constraints
1 <= |X| <=10^5
1 <= n <= 10

Sample Input
333
1
3

Sample Output
6
*/

/*
https://ide.codingblocks.com/s/34722
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/string-matching-google-3dc355a5/editorial/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
string s;
int n, numsMask;
ll dp[100001][1<<10];

ll solve(int i, int mask) {
    if(i==s.size()) {
        return 0;
    }
    if((mask&numsMask) == numsMask) {
        return 1;
    }

    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }

    int digit = s[i]-'0';
    ll ways = 0;

    ways = solve(i+1, mask);
    ways += solve(i+1, (mask|(1<<digit)) );

    return dp[i][mask] = ways;
}

int main() {
    int num;

    cin>>s;
    cin>>n;

    numsMask = 0;
    for(int i=1; i<=n; i++) {
        cin>>num;
        numsMask = numsMask|(1<<num);
    }

    memset(dp, -1, sizeof dp);

    cout<<solve(0,0);

    return 0;
}
