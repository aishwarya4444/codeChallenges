/*

https://www.codechef.com/INOIPRAC/problems/INOI1301

Calvin wakes up early one morning and finds that all his friends in the hostel are asleep.
To amuse himself, he decides to play the following game :
    He draws a sequence of N squares on the ground, numbered 1 to N, and writes an integer in each square.
    He starts at square k (1 ≤ k ≤ N). The game consists of one forward phase followed by one backward phase.
        :- In the forward phase, Calvin makes zero or more moves of the following type
            : if his current position is p, he can jump to p+1 or p+2 as long as he stays within the N squares.
        :- In the backward phase, Calvin makes zero or more moves of the following type
            : if his current position is p, he can jump to p−1 or p−2 as long as he stays within the N squares.

He plays such that he finally ends up at square 1, and then he stops.
He starts with a score of 0, and each time he jumps from square i to square j,
he adds the integer written in square j to his score.
Find the maximum score Calvin can obtain by playing this game.
Recall that Calvin must start at square k and end at square 1.
The integer on the square where he starts is not included in his score.

For example,
suppose N = 5 and the numbers in squares are 5, 3, −2, 1, 1.
If k = 2, Calvin starts on the second square.
He can make a forward move to square 4, another to square 5,
a backward move to square 4, another to square 2, and another to square 1.
His total score is 1+1+1+3+5 = 11. You can check that this is the maximum score possible.

Input Format
• Line 1 : Two space-separated integers, N and k, with 1 ≤ k ≤ N.
• Line 2 : A space-separated sequence of N integers, the numbers in squares 1, 2 . . . , N .

Constraints
1 ≤ N ≤ 2*10^5
-1000 <= Ai <= 1000

Output Format
A single line with a single integer, the maximum score Calvin can obtain by playing the game.

Sample Input
5 2
5 3 -2 1 1
Sample Output
11
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200003];
ll dpf[200003];
ll dpb[200003];

int main() {
	int n, k;
	ll res = 0;

	cin>>n>>k;

	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}

	for(int i=k+1; i<=n; i++) {
		dpf[i] = a[i]+max(dpf[i-1], dpf[i-2]);
	}

	dpb[1] = a[1];
	dpb[2] = a[1]+a[2];
	for(int i=3; i<=n; i++) {
		dpb[i] = a[i]+max(dpb[i-1], dpb[i-2]);
	}

	for(int i=k; i<=n; i++) {
		res = max(res, dpf[i]+dpb[i]-a[i]);
	}

	cout<<res;

	return 0;
}

/*
// WA as position from where return happened was included twice
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200001];
ll dp[200001];

int main() {
	int n, k;

	cin>>n>>k;
	k--;

	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	dp[k+1] = a[k+1];
	for(int i=k+2; i<n; i++) {
		dp[i] = a[i]+max(dp[i-1], dp[i-2]);
	}

	dp[n-2] = max(dp[n-2], a[n-2]+dp[n-1]);
	for(int i=n-3; i>=0; i--) {
		dp[i] = a[i]+max(dp[i+1], dp[i+2]);
	}

	cout<<dp[0];

	return 0;
}
*/