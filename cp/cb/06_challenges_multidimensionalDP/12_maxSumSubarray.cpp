/*
Find the maximum sum subarray in the given 2D array.

Input Format
First line of every test case consists of 2 integers R and C , denoting number of rows and columns.
Second line consists of R*C spaced integers denoting number of elements in array.

Constraints
1 <= R, C <= 100

Output Format
Print the maximum possible sum of any rectangle which can be formed in that 2D matrix.

Sample Input
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6

Sample Output
29
Explanation
 1  2 -1 -4 -20
-8 -3  4  2  1
 3  8 10  1  3
-4 -1  1  7 -6
The maximum sum rectangle which can be formed in this subarray has coordinates
leftTop(2,2) and rightBottom(4,4) according to 1-based indexing.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
// grid
int a[1001][1001];

int main() {
    int r, c, val, ans, sum, maxSum;

    cin>>n>>m;
    memset(a, 0, sizeof a);

    for(r=1; r<=n; r++) {
        for(c=1; c<=m; c++) {
            cin>>a[r][c];
            a[r][c] += a[r][c-1];
        }
    }

    ans = a[1][1];
    for(int c1=1; c1<=m; c1++) {
        for(int c2=c1; c2<=m; c2++) {
            sum = 0;
            maxSum = ans;
            for(r=1; r<=n; r++) {
                val = a[r][c2]-a[r][c1-1];
                sum += val;
                if(sum<val) sum = val;
                if(maxSum<sum) maxSum = sum;
            }
            ans = max(ans, maxSum);
        }
    }

    cout<<ans<<endl;

    return 0;
}
