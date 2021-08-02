/*
https://codeforces.com/problemset/problem/276/D

https://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/

Given two integers l and r , your task is to find the maximum xor of two integers both of which lying between l and r inclusive.

Input Format
The first line contains l and r separated by a space.

Constraints
l, r<=10^18

Output Format
Output is a single number denoting the maximum xor

Sample Input
79242383109441603 533369389165030783

Sample Output
576460752303423487
*/

#include<bits/stdc++.h>
using namespace std;

#define ll  long long

int main() {
    ll l, r, maxXor, ans=1;

    cin>>l>>r;

    maxXor = l^r;
    while( maxXor ) {
        maxXor >>= 1;
        ans <<= 1;
    }

    cout<<ans-1;

    return 0;
}
