/*

https://leetcode.com/problems/wildcard-matching/

// bottom up - LCS pattern
// https://leetcode.com/problems/wildcard-matching/discuss/1280930/C%2B%2B-easy-dp-solution

Given a text 'str' and a wildcard pattern 'pattern', The wildcard pattern can include the characters ‘?’ and ‘ * ’.
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)
Find out if the given text matches the pattern.

Input Format
Each testcase contains two strings. First line contains the text string and the second line contains the pattern.

Constraints
Size(str)*Size(pattern) < 100000000

Output Format
Print 1 if the string matches the pattern, else print 0.

Sample Input
aa
a*a

Sample Output
1
*/

// top down using map
#include<bits/stdc++.h>
using namespace std;

#define ll long long
string str, pat;
map<pair<int, int> , bool> dp;

bool solve(int s, int p) {
    if(s==str.size() && p==pat.size()) {
        return true;
    }
    if(s>str.size() || p==pat.size()) {
        return false;
    }

    if(dp.count({s, p})) {
        return dp[{s, p}];
    }

    if(pat[p]=='?' || str[s]==pat[p]) {
        return dp[{s, p}] = solve(s+1, p+1);
    }
    if(pat[p]=='*') {
        return dp[{s, p}] = solve(s+1, p) || solve(s, p+1);
    }
    return dp[{s, p}] = false;
}

int main() {
    cin>>str>>pat;

    cout<<solve(0, 0);

    return 0;
}



// top down using 1d array
#include<bits/stdc++.h>
using namespace std;

#define ll long long
string str, pat;
int dp[10000000];

int solve(int s, int p) {
    if(s==str.size() && p==pat.size()) {
        return 1;
    }
    if(s>str.size() || p==pat.size()) {
        return 0;
    }

    if(dp[s*pat.size() + p] != -1) {
        return dp[s*pat.size() + p];
    }


    if(pat[p]=='?' || str[s]==pat[p]) {
        return dp[s*pat.size() + p] = solve(s+1, p+1);
    }
    if(pat[p]=='*') {
        return dp[s*pat.size() + p] = solve(s+1, p) || solve(s, p+1);
    }
    return dp[s*pat.size() + p] = 0;
}

int main() {
    cin>>str>>pat;
    memset(dp, -1, sizeof dp);

    cout<<solve(0, 0);

    return 0;
}

