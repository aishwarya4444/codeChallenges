/*
https://www.codechef.com/problems/AOPN
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;
string s;
ll dp[20][11][11][2][2][2][2];

ll solve(int pos, int last, int second_last, bool tight, bool odd, bool even, bool start) {
    if(pos==s.size()) {
        return odd && even;
    }

    if(dp[pos][last][second_last][tight][odd][even][start] != -1) {
        return dp[pos][last][second_last][tight][odd][even][start];
    }

    ll ret = 0;

    if(start) {
        int end = tight ? (s[pos]-'0') : 9;
        for(int i=0; i<=end; i++) {
            ret += solve(pos+1, i, last, tight&(i==end), odd|(i==second_last), even|(i==last), 1);
        }
    } else {
        ret = solve(pos+1, last, second_last, tight&(s[pos]=='0'), odd, even, start);
        int end = tight ? (s[pos]-'0') : 9;
        for(int i=1; i<=end; i++) {
            ret += solve(pos+1, i, second_last, tight&(i==end), odd, even, 1);
        }
    }
    return dp[pos][last][second_last][tight][odd][even][start] = ret;
}

int main() {
    int t;
    ll resA, resB;

    cin>>t;

    while(t--) {
        cin>>a>>b;

        s = a;
        memset(dp, -1, sizeof dp);
        resA = solve(0, 10, 10, 1, 0, 0, 0);

        s = b;
        memset(dp, -1, sizeof dp);
        resB = solve(0, 10, 10, 1, 0, 0, 0);

        cout<<resB-resA<<endl;
    }

    return 0;
}
