#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canDecode(string st) {
    int num = stoi(st);

    if(st.size()==1) {
        return num>=1 && num<=9;
    }

    return num>=10 && num<=26;
}

int main() {
    int t;
    string s;

    cin>>t;

    while(t--) {
        cin>>s;
        int n = s.size();
        vector<ll> dp(n+1, 0);

        dp[0] = 1;
        if(canDecode(s.substr(0, 1))) {
            dp[1] = 1;
        }

        for(int i=1; i<n; i++) {
            if(canDecode(s.substr(i, 1))) {
                dp[i+1] += dp[i];
            }
            if(canDecode(s.substr(i-1, 2))) {
                dp[i+1] += dp[i-1];
            }
        }

        cout<<dp[n]<<endl;
    }

    return 0;

}
