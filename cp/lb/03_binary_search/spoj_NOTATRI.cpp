/*
https://www.spoj.com/problems/NOTATRI/


Triangle is formed if a+b < c

Now I have to win, so I will choose a,b,c such that triangle cannot be formed
So, check for a+b >= c


A degenerate triangle has all three of its vertices lying on the same straight line.
So the triangle is squashed completely flat.
One type of degenerate triangle has one vertex lying between the other two.
This triangle has zero area, its angles are 0∘, 0∘ and 180∘
Its side lengths satisfy c=a+b, where c is the longest side.
Another type of degenerate triangle has two vertices at the same place.
It is difficult to say what the angles of such a shape are.
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int s[2000];



int main() {
	int lo, m, hi, total;

	while(true) {
		cin>>N;
		if(N==0) {
			break;
		}

		for(int n=0; n<N; n++) {
			cin>>s[n];
		}

		sort(s, s+N);
		total = 0;

		for(int a=2; a<N; a++) {
			for(int b=1; b<a; b++) {
				lo = 0;
				hi = b-1;
				while(lo<=hi) {
					m = (lo+hi)/2;
					if(s[m]+s[b] >= s[a]) {
						hi = m-1;
					} else {
						lo = m+1;
					}
				}
				total += lo;
			}
		}

		cout<<total<<endl;
	}

	return 0;
}
