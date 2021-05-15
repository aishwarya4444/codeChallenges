/*
https://www.spoj.com/problems/RENT/

https://www.geeksforgeeks.org/weighted-job-scheduling/
https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/

LIS dp used
binary search possible but not figured yet
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
	int st, end, p;
	Job(int _st, int _end, int _p) {
		st = _st;
		end = _end;
		p = _p;
	}
};

struct compareJob {
	bool operator()(const Job &j1, const Job &j2) {
		return j1.st < j2.st;
	}
};

int T, N, st, d, p;
vector<Job> jobs;

void solve() {
	vector<long> dp(N, 0);
	long ans = 0;

	for(int i=0; i<N; i++) {
		dp[i] = jobs[i].p;
		for(int j=0; j<i; j++) {
			if(jobs[j].end<jobs[i].st && dp[j]+jobs[i].p>dp[i]) {
				dp[i] = dp[j]+jobs[i].p;
			}
		}
		ans = max(ans, dp[i]);
	}

	cout<<ans<<'\n';
}

int main() {

	cin>>T;

	while(T--) {
        cin>>N;

        jobs.clear();
        for(int n=0; n<N; n++) {
            cin>>st>>d>>p;
            jobs.push_back({st, st+d, p});
        }

        sort(jobs.begin(), jobs.end(), compareJob());

        solve();
	}

	return 0;
}