/*
Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.

Input Format
First line contains first string . Second line contains second string. Third line contains the third string.

Constraints
The length of all strings is |s|< 200

Output Format
Output an integer denoting the length of longest common subsequence of above three strings.

Sample Input
GHQWNV
SJNSDGH
CPGMAH

Sample Output
2

Explanation
"GH" is the longest common subsequence
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[200][200][200];
string a, b, c;

int da[] = {0, 0, 0, 1, 1, 1};
int db[] = {0, 1, 1, 0, 0, 1};
int dc[] = {1, 0, 1, 0, 1, 0};

int solve(int i, int j, int k) {
    if(i<0 || j<0 || k<0) {
        return 0;
    }

    if(dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    int ways = 0;

    if(a[i]==b[j] && b[j]==c[k]) {
        ways = 1 + solve(i-1, j-1, k-1);
    } else {
        for(int d=0; d<6; d++) {
            ways = max(ways, solve(i-da[d], j-db[d], k-dc[d]));
        }
    }

    return dp[i][j][k] = ways;
}

int main() {
    cin>>a>>b>>c;

    memset(dp, -1, sizeof dp);

    cout<<solve(a.size()-1, b.size()-1, c.size()-1);

    return 0;
}
