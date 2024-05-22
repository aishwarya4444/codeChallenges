/*
https://atcoder.jp/contests/dp/tasks/dp_f
*/

// solution 1 using top down
#include<bits/stdc++.h>
using namespace std;

int dp[3001][3001];

string a, b;

int solve(int i, int j) {
	if(i==a.size() || j==b.size()) return 0;

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	int ans = 0;

	if(a[i]==b[j]) {
		ans = 1+solve(i+1, j+1);
	} else {
		ans = max(solve(i+1, j), solve(i, j+1));
	}

	return dp[i][j] = ans;
}

int main()
{
	string res="";

	cin>>a;
	cin>>b;

	memset(dp, -1, sizeof dp);

	solve(0, 0);

	int i=0, j=0;

	while(i<a.size() && j<b.size()) {
		if(a[i]==b[j]) {
			res+=a[i];
			i++;
			j++;
		} else if(dp[i][j+1] > dp[i+1][j]) {
			j++;
		} else {
			i++;
		}
	}

	cout<<res;

	return 0;
}


// solution 2 using bottom up
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[3001][3001];
string s, t, res;

int main() {
    int i, j;
    int S, T;

    cin>>s>>t;

    S = s.size();
    T = t.size();

    s = '_'+s;
    t = '_'+t;

    memset(dp, 0, sizeof dp);
    for(i=1; i<=S; i++) {
        for(j=1; j<=T; j++) {
            if(s[i]==t[j]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    i=S;
    j=T;
    while(i>0 && j>0) {
        if(s[i]==t[j]) {
            res += s[i];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(res.begin(), res.end());
    cout<<res;

    return 0;
}
