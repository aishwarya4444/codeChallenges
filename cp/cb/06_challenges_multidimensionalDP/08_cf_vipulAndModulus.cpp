/*
https://codeforces.com/problemset/problem/401/D
https://codeforces.com/blog/entry/10842
https://codeforces.com/problemset/submission/401/122073235


Vipul wants to buy his favourite bike Royal Enfield.
The bike is priced at N dollars.
He already has the amount with him and wants to take his girlfriend for a ride
but she poses a condition and asks him a question.
She always gives him challenging tasks and this time she gives him a number M
and asks him to find out how many numbers can be formed by rearranging digits of number N whose modulo M is 0?
NOTE :- You have to permute digits of N and only consider the numbers which do not have leading zeroes.

Input Format
First line consists of number of test cases T. Each test case consists of number N and M.

Constraints
1 <= N <= 10^18
1 <= M <= 100

Output Format
The answer for every test case in a new line.

Sample Input
1
223 4

Sample Output
1

Explanation
The numbers formed on rearrangement are 232 , 223 , 322 out of which only 232 % 4 = 0.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// ll gave MLE so used int DP array
int dp[1<<18][101];
string n;
int m;

int solve(int mask, int mod) {
    if(mask == (1<<n.size())-1) {
        return mod==0 ? 1 : 0;
    }
    if(dp[mask][mod] != -1) {
        return dp[mask][mod];
    }

    ll ans = 0;
    vector<bool> used(10, false);

    for(int i=0; i<n.size(); i++) {
        if(n[i]=='0' && mask==0) {
            continue;
        }
        if( (mask&(1<<i))==0 && used[n[i]-'0']==false) {
            used[n[i]-'0'] = true;
            ans = ans + solve(mask|(1<<i), (mod*10+n[i]-'0')%m);
        }
    }

    return dp[mask][mod] = ans;
}

int main() {
	int t;

	cin>>t;
		while(t--) {
		memset(dp, -1, sizeof dp);
		cin>>n;
		cin>>m;
		cout<<solve(0,0)<<endl;
	}

    return 0;
}
