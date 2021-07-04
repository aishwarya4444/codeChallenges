/*
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem.
Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash.
To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced.
A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence to any value you wish to.
Can you help Mancunian solve this version of the classical problem?

Input Format
The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively.
The second line contains N integers denoting the elements of the first sequence.
The third line contains M integers denoting the elements of the second sequence.

Constraints
1 <= N, M <= 2000
1 <= k <= 5
1 <= element in any sequence <= 109

Output Format
Print the answer in a new line.

Sample Input
5 5 1
1 2 3 4 5
5 3 1 4 2

Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int a[2000];
int b[2000];
int N, M, k;
int dp[2000][2000][6];

int k_lcs(int i, int j, int change) {
    if(i==N || j==M) {
        return 0;
    }

    if(dp[i][j][change] != -1) {
        return dp[i][j][change];
    }

    int way1 = 0, way2 = 0, way3 = 0;

    if(a[i]==b[j]) {
        way1 = 1+k_lcs(i+1, j+1, change);
    } else {
        way2 = max(k_lcs(i, j+1, change), k_lcs(i+1, j, change));
        if(change) {
            way3 = 1+k_lcs(i+1, j+1, change-1);
        }
    }

    return dp[i][j][change] = max({way1, way2, way3});
}

int main() {
    cin>>N>>M>>k;

    memset(dp, -1, sizeof dp);

    for(int i=0; i<N; i++) {
        cin>>a[i];
    }

    for(int i=0; i<M; i++) {
        cin>>b[i];
    }

    cout<<k_lcs(0, 0, k);

    return 0;
}
