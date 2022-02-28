// top down 1
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;
int n;
ll dp[3000][3000][2];
// constraints are more in this question

ll solve(int i, int j, int player) {
    if(i>j) {
        return 0;
    }

    // we allow memoization to a certain extent only
    if(i<3000 && j<3000)
        if(dp[i][j][player]!=-1) {
            return dp[i][j][player];
        }

    ll op1, op2, ans;
    if(player==0) {
        // Piyush picks a[i] or a[j] and turn goes to Nimit
        // value which is picked is counted in Piyush's score
        op1 = a[i] + solve(i+1, j, 1);
        op2 = a[j] + solve(i, j-1, 1);
        ans = max(op1, op2);
    } else {
        // Nimit picks a[i] or a[j] and turn goes to Piyush
        // value picked is not counted in Piyush's score
        op1 = solve(i+1, j, 0);
        op2 = solve(i, j-1, 0);
        ans = min(op1, op2);
    }


    if(i<3000 && j<3000)
        return dp[i][j][player] = ans;

    return ans;
}

int main() {
    int val;

    cin>>n;

    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++) {
        cin>>val;
        a.push_back(val);
    }

    cout<<solve(0, n-1, 0);

    return 0;

}


// top down 2
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;
int n;
ll dp[5000][5000];

ll solve(int i, int j) {
    if(i>j) {
        return 0;
    }

    // we allow memoization to a certain extent only
    if(i<5000 && j<5000)
    	if(dp[i][j]!=-1) {
	        return dp[i][j];
	    }

    ll op1 = a[i] + min(solve(i+1, j-1), solve(i+2, j));
    ll op2 = a[j] + min(solve(i, j-2), solve(i+1, j-1));

    if(i<5000 && j<5000)
    	return dp[i][j] = max(op1, op2);

    return max(op1, op2);
}

int main() {
    int val;

    cin>>n;

    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++) {
        cin>>val;
        a.push_back(val);
    }

    cout<<solve(0, n-1);

    return 0;

}