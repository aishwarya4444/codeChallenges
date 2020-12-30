/*
https://www.spoj.com/problems/PPATH/

        # bfs
        # primes
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> primes(10000, true);
vector<bool> visited;

void setPrimes() {
	int n, m;

	primes[0] = primes[1] = false;
	for(n=2; n*n<=10000; n++) {
		if(primes[n]) {
			for(m=n+n; m<=10000; m+=n) {
				primes[m] = false;
			}
		}
	}
}

int bfs(string src, string dest) {
	queue<string> q;
	int level=0, N;
	string num;

	if(src == dest) {
		return level;
	}
	q.push(src);
	visited = vector<bool>(10000, false);
	while(q.size()) {
		N = q.size();
		level++;
		while(N--) {
			src = q.front();
			q.pop();
			if(visited[stoi(src)]) {
				continue;
			}
			visited[stoi(src)] = true;

			for(int i=0; i<src.size(); i++) {
				string digits = "0123456789";

				num = src;
				digits.erase(digits.begin()+(src[i]-'0'));
				if(i==0) {
					digits.erase(digits.begin());
				}

				for(auto digit: digits) {
					num[i] = digit;
					if(primes[stoi(num)] && visited[stoi(num)]==false) {
						if(num == dest) {
							return level;
						}
						q.push(num);
					}
				}
			}
		}
	}

	return -1;
}

int main() {
	int len, T;
	string n1, n2;

	cin>>T;

	setPrimes();
	while(T--) {
		cin>>n1>>n2;
		len = bfs(n1, n2);
		if(len<0) {
			cout<<"Impossible\n";
		} else {
			cout<<len<<endl;
		}
	}

	return 0;
}
