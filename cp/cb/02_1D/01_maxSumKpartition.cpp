/*
Agarwal has a habit of creating Ajeeb Samasya as usual and Shubham always comes to his rescue.
This is time he has created another samasya which is as follows.
Read carefully! Shubham has an array of N integers and an integer K.
He wants to create a subsequence of this array with some conditions applied.
He builds ceil(N/K) blocks of this array with size of each block as [i∗K+1,min((i+1)∗k,N)] for 0≤i≤N/K.
For two consecutive integers in this subsequence, he wants the integers to be of two different blocks.
(It is not a compulsion to have one integer from each block).
Also, lets say the indexes of any two integers of this subsequence be i and j, then he wants |i−j| != K.
Shubham takes the sum of integers in the subsequence.
He wonders what can be the maximum sum obtained? Help shubham in this samasya.

Input Format
First line contains two space separated integers : N and K Second line contains N space separated integers : A1, A2,…, AN

Constraints
1 ≤ N ≤ 2∗10^6

1 ≤ K ≤ N

−10^9 ≤ Ai ≤ 10^9

Output Format
print a single integer describing maximum sum that can be obtained.

Sample Input
6 5
5 4 3 2 1 -1
Sample Output
5
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	ll val;
	int idx;
	node(ll v, int i) {
		val = v;
		idx = i;
	}
};

struct cmpNode {
	bool operator()(const node &n1, const node &n2) {
		return n1.val>n2.val;
	}
};

// min heap
priority_queue<node, vector<node>, cmpNode> pq;
ll a[2000001];
ll dp[2000001];

int main() {
	int n, k;
	int i1, i2;
	ll v1, v2;

	cin>>n>>k;

	for(int i=0; i<k; i++) {
		cin>>a[i];
		pq.push({a[i], i});
		if(pq.size()>2) {
			pq.pop();
		}
	}

	for(int i=k; i<n; i++) {
		cin>>a[i];
		if(i%k == 0) {
			// 2nd max
			v1 = pq.top().val;
			i1 = pq.top().idx;
			pq.pop();
			// 1st max
			v2 = pq.top().val;
			i2 = pq.top().idx;
			pq.pop();
		}
		if(i-i2 != k) {
			dp[i] = max(v2, a[i]+v2);
		} else {
			dp[i] = max(v1, a[i]+v1);
		}
		dp[i] = max(dp[i], v2);
		pq.push({dp[i], i});
		if(pq.size()>2) {
			pq.pop();
		}
	}

	if(pq.size()==2) {
		pq.pop();
	}
	cout<<pq.top().val;

	return 0;
}
