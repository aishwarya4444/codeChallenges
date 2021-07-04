/*
https://leetcode.com/problems/longest-valid-parentheses/

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;
    int n, res=0;

    cin>>s;
    n = s.size();

    vector<int> dp(n, 0);

    for(int i=1; i<n; i++) {
        if(s[i]==')') {
            if(s[i-1]=='(') {
                dp[i] = 2 + ((i-2>=0) ? dp[i-2] : 0);
            } else if(i-1-dp[i-1]>=0 && s[i-1-dp[i-1]]=='(') {
                dp[i] = 2 + dp[i-1] + ((i-1-dp[i-1]-1>=0) ? dp[i-1-dp[i-1]-1] : 0);
            }
            res = max(res, dp[i]);
        }
    }

    cout<<res;

    return 0;

}

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int l, r, n, N=s.size(), len=0;

        l=0;
        r=0;
        for(n=0; n<N; n++) {
            if(s[n]=='(') {
                l++;
            } else {
                r++;
            }
            if(l==r) {
                len = max(len, l+r);
            } else if(r>l) {
                l=0;
                r=0;
            }
        }

        l=0;
        r=0;
        for(n=N-1; n>=0; n--) {
            if(s[n]=='(') {
                l++;
            } else {
                r++;
            }
            if(l==r) {
                len = max(len, l+r);
            } else if(l>r) {
                l=0;
                r=0;
            }
        }

        return len;
    }
};
*/