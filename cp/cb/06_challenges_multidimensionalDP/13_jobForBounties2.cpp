/*
Mike is given N jobs and each job i is characterized by
duration[i] (time taken to complete ith job),
reward[i] (bounties he will get on finishing ith job) and
deadline[i] (the time upto which ith job must be completed if it is to be done).
He has T time and can do at most one job at a time.
Now, he has to choose jobs maximizing the number of bounties he can get after T time units.

Input Format
The first line contains two integers, T and n, separated by space.
The next line contains N integers, separated by spaces, ith integer representing reward[i].
The next line contains N integers, separated by spaces, ith integer representing duration[i].
The next line contains N integers, separated by spaces, ith integer representing deadline[i].

Constraints
1 <= N <= 100
1 <= T,duration[i],reward[i],deadline[i] <= 1000

Output Format
Print maximum number of bounties Mike can get after T time units.

Sample Input
20 5
4 3 2 5 4
7 6 4 6 6
9 13 12 13 20

Sample Output
13

Explanation
Mike can do first, forth and fifth jobs to get 13 bounties (4+5+4) in the given order.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    int reward, time, dead;
};
node a[100];
int t, n;
int dp[101][1001];

int solve(int i, int time) {
    if(i==n || time>=t) {
        return 0;
    }

    if(dp[i][time] != -1) {
        return dp[i][time];
    }

    int total = 0;

    total = solve(i+1, time);

    if(time+a[i].time <= a[i].dead) {
        total = max(total, a[i].reward + solve(i+1, time+a[i].time));
    }

    return dp[i][time] = total;
}

int main() {
    cin>>t>>n;

    for(int i=0; i<n; i++) {
        cin>>a[i].reward;
    }
    for(int i=0; i<n; i++) {
        cin>>a[i].time;
    }
    for(int i=0; i<n; i++) {
        cin>>a[i].dead;
    }

    memset(dp, -1, sizeof dp);

    cout<<solve(0, 0);

    return 0;
}
