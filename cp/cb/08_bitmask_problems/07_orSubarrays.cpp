/*

https://www.geeksforgeeks.org/sum-of-bitwise-or-of-all-subarrays-of-a-given-array-set-2/

Given an array A1, A2 . . . AN , find the sum of bitwise OR of all the subarrays of A.

Input Format
The first line contains N number, followed by N numbers in the next line.

Constraints
N<=10^5
Ai<=10^9

Output Format
Output is a single number denoting the sum.

Sample Input
5
1 2 3 4 5

Sample Output
71
*/


#include<bits/stdc++.h>
using namespace std;

#define ll  long long

int n;
int a[100000];
int maxNum;


ll solve() {

    int BITS = log2(maxNum)+1;
    int count, total, arr;
    ll sum = 0;

    for(int i=0; i<BITS; i++) {
        vector<int> v;
        for(int j=0; j<n; j++) {
            if(a[j]&(1<<i)) continue;
            v.push_back(j);
        }

        // number of contiquous a[j] where ith bit is not set
        count = 1;
        // total number of subarrays where ith bit is not set
        total = 0;
        // total number os possible aubarrays
        arr = n*(n+1)/2;

        for(int j=1; j<v.size(); j++) {
            if(v[j]-v[j-1] == 1) {
                count++;
            } else {
                total += count*(count+1)/2;
                count = 1;
            }
        }

        if(count) {
            total += count*(count+1)/2;
        }
        if(v.size() == 0) {
            total = 0;
        }
        arr -= total;
        sum += arr*pow(2, i);
    }

    return sum;
}

int main() {
    maxNum = INT_MIN;

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>a[i];
        maxNum = max(a[i], maxNum);
    }

    cout<<solve();

    return 0;
}
