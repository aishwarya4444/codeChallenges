/*
https://www.codechef.com/problems/LIONS
https://www.codechef.com/viewsolution/46980219
https://www.codechef.com/viewsolution/48090545

Kaleen Bhaiya is impressed with Guddu and Bablu so he decides to give them some bullets for their guns.
He gives N boxes of bullets (Numbered from 1 to N) to guddu and N boxes of bullets(Numbered from 1 to N) to Bablu.

Now Kaleen Bhaiya puts some conditions:

Guddu can take maximum A boxes of bullets from his set of boxes and Bablu can take maximum B boxes of bullets from his set of boxes.
Only one of them can take box with same number i.e if Guddu takes box 1 from his set then Bablu can't take box 1 from his set.
They have to start from box 1 and go till box N.
They cannot skip any box and they cannot go back.
Guddu and Bablu are brothers so they decides to take the maximum amount of bullets and will divide them afterwards
but Guddu is weak in studies and Bablu bhaiya needs to help Golu for college elections so they asked you for help
and in return they will give you a Katta for free.

Input Format
First line will contain N, A, B.
The second line contains N integers. The ith integer represents number of bullets in ith box given to Guddu.
The third line also contains N integers. The ith integer represents number of bullets in ith box given to Bablu.

Constraints
1 ≤ N ≤ 5000
0 ≤ A,B ≤ 5000
N <= A+B
0 ≤ Ai ≤ 10^9

Output Format
Print a single integer representing the maximum bullets they can get.

Sample Input
5 3 4
8 2 5 3 7
8 3 4 6 2

Sample Output
29

Explanation
Guddu will take boxes with number 1, 3, 5.
Bablu will take boxes with number 2, 4.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int x[5001];
int y[5001];
int n, a, b;
ll dp[5001][5001];

ll solve(int i, int a, int b) {
    if(i==n) {
        return 0;
    }

    if(dp[a][b] != -1) {
        return dp[a][b];
    }

    ll res =0;
    if(a) {
        res = max(res, x[i]+solve(i+1, a-1, b));
    }
    if(b) {
        res = max(res, y[i]+solve(i+1, a, b-1));
    }

    return dp[a][b] = res;
}

int main() {
    cin>>n>>a>>b;

    for(int i=0; i<n; i++) {
        cin>>x[i];
    }

    for(int i=0; i<n; i++) {
        cin>>y[i];
    }

    memset(dp, -1, sizeof dp);

    cout<<solve(0, a, b);

    return 0;
}
