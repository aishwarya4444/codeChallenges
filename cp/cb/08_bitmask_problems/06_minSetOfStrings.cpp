/*
Given a set of strings S ,each of which consists of ‘A’,’B’,and ‘C’ only.
You want to choose some set of strings such that you have atleast one of each kind, i.e., A,B,C.
In addition of that choosing string S[i] costs c[i], so you should find minimum cost to have all kinds of characters.

Input Format
The first line contains an integer N, followed by strings in the next line separated by a new line.

Constraints
Number of strings <=1000
c[i]<=100000
Size of each string is upto 3.

Output Format
Output is a single number denoting the minimum cost.

Sample Input
5
ABC
AB
A
B
C
1
2
2
3
4

Sample Output
1
*/

#include<bits/stdc++.h>
using namespace std;

#define ll  long long

int n;
string s[1000];
int c[1000];
ll dp[1000][1<<3];

ll solve(int i, int mask) {
    if(mask == (1<<3)-1) {
        return 0;
    }

    if(i == n ) {
        return 1e9;
    }

    if(dp[i][mask] != 1e9) {
        return dp[i][mask];
    }

    int _mask = mask;

    ll ans = solve(i+1, _mask);

    for(char ch: s[i]) {
        int num = ch-'A';
        _mask = _mask|(1<<num);
    }

    ans = min(ans, c[i] + solve(i+1, _mask));

    return dp[i][mask] = ans;
}

int main() {
    cin>>n;
    cin.ignore();

    for(int i=0; i<n; i++) {
        cin>>s[i];
    }
    for(int i=0; i<n; i++) {
        cin>>c[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<8; j++) {
            dp[i][j] = 1e9;
        }
    }

    cout<<solve(0, 0);

    return 0;
}
