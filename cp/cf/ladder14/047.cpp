/*
https://codeforces.com/problemset/problem/322/B

If there are no "mixing bouquet" then the answer will be r/3 + g/3 + b/3.
One important observation is that:
	There always exist an optimal solution with less than 3 mixing bouquet.

The proof is here:
	Once we get 3 mixing bouquet, we can change it to (1 red bouquet + 1 green bouquet + 1 blue bouquet)

So we can try 0, 1, 2 mixing bouquet and make the remain 3 kind of bouquets use above greedy method. Output one with largest outcome.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int color[3];
	int r, g, b;
	ll total=0;

	cin>>color[0]>>color[1]>>color[2];

	sort(color, color+3);

	r = color[0];
	g = color[1]-r;
	b = color[2]-r;

	total = r + g/3 + b/3;

	// 3 5 5
	// should give 4
	if(g%3==2 && b%3==2 && r) total++;

	cout<<total;

	return 0;
}
