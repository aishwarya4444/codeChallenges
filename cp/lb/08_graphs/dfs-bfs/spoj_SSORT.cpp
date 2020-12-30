/*
https://www.spoj.com/problems/SSORT/
https://www.codechef.com/problems/SSORT
http://isolvedaproblem.blogspot.com/2012/02/silly-sort.html
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;
vector<bool> visited;

int solve() {
	unordered_map<int, int> loc;
	int i, j, res=0, sum1, sum2, k, total, minVal;

	sort(b.begin(), b.end());
	for(i=0; i<n; i++) {
		loc[b[i]] = i;
	}
	for(i=0; i<n; i++) {
		if(visited[i]) {
			continue;
		}
		/* element in a[] is at correct position */
		if(loc[a[i]] == i) {
			visited[i] = true;
			continue;
		}

		sum1 = 0; /* minimum possible sum in current cycle */
		sum2 = 0; /* excahnge minVal of this cycle with b[0] and then find minimum sum and then exchange again */
		total = 0;  /* sum of all values in current cycle excluding minVal */
		k = 0; /* length of current cycle */
		minVal = a[i]; /* minVal in current cycle */
		j = i;
		while(visited[j] == false) {//cout<<k<<"  "<<j<<" "<<visited[j]<<endl;
			visited[j] = true;
			k++;
			total += a[j];
			minVal = min(minVal, a[j]);
			j = loc[a[j]];
		}

		total -= minVal;
		sum1 = total + (k-1)*minVal;
		sum2 = total + (k-1)*b[0] + 2*(b[0]+minVal);
		res += min(sum1, sum2);
	}

	return res;
}

int main() {
	int i, test=0;

	while(true) {
		test++;
		cin>>n;
		if(n==0) {
			break;
		}

		a = vector<int>(n, 0);
		b = vector<int>(n, 0);
		visited = vector<bool>(n, false);

		for(i=0; i<n; i++) {
			cin>>a[i];
			b[i] = a[i];
		}

		cout<<"Case "<<test<<": "<<solve()<<"\n\n";
	}

	return 0;
}
