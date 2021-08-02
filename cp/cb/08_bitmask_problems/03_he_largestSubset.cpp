/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/sherlock-and-coprime-subset/
http://gautamdp.blogspot.com/2016/03/sherlock-and-coprime-subset-dpbit.html

Given an array A1, A2 . . . An
What is the size of the largest subset of the array such that the each pair of elements in the subset is coprime.

Input Format
The first line contains an integer N, followed by N numbers in the next line.

Constraints
N<=50
Ai<=50

Output Format
Output is a single number denoting the size.

Sample Input
5
2 3 2 3 2

Sample Output
2
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> a;
vector<int> p;
ll dp[51][1<<15];

// prime numbers till 50
void sieve() {
    vector<bool> n(51, false);

    n[2] = true;
    p.push_back(2);
    for(int i=3; i<51; i+=2) {
        n[i] = true;
    }

    for(int i=3; i<51; i+=2) {
        if(n[i]) {
            p.push_back(i);
            for(int j=i*i; j<51; j+=i) {
                n[j] = false;
            }
        }
    }

    // for(int num: p) {
    //     cout<<num<<' '<<endl;
    // }
}

int prepareMask(int num) {
    int mask = 0;
    for(int i=0; i<p.size(); i++) {
        if(num%p[i] == 0) {
            mask = mask|(1<<i);
        }
    }
    return mask;
}

ll solve(int i, int mask) {
    if(i==n) {
        return 0;
    }
    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }

    ll exclude = solve(i+1, mask), include = 0;

    if((mask&a[i]) == 0) {
        include = 1 + solve(i+1, mask|a[i]);
    }

    return dp[i][mask] = max(exclude, include);
}

int main() {
    int num;

    sieve();
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>num;
        a.push_back(prepareMask(num));
    }

    memset(dp, -1, sizeof dp);
    cout<<solve(0, 0)<<endl;

    return 0;
}
