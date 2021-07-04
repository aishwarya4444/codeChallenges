/*
Given a “2 x n” board and tiles of size “2 x 1”.
Print the number of ways to tile the given board using the 2 x 1 tiles.
A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.

Input Format
The only line of the input contains N to represent the second dimension of the board.

Constraints
1<= N < 100000000

Output Format
Print the number of ways to tile the given board .

Note: Since the answer can be huge, print ans % 1000000007.

Sample Input
3
Sample Output
3
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    int a, b, c;

    cin>>n;

    a = 1;
    b = 1;
    c = 1;
    for(int i=2; i<=n; i++) {
        c = (a+b)%mod;
        a = b;
        b = c;
    }

    cout<<c;
}
