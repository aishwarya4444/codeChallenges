/*
https://www.hackerrank.com/contests/test-contest-47/challenges/m158-multiple-euclid/problem

You will be given two relatively prime integers a and b. You must give two coefficients u and v, such that au+bv=1.

Input Format

A single line with two integers, a and b. These integers are guaranteed to be relatively prime, and will lie between 1 and 2^128-1 inclusive.

Output Format

Two space-separated integers u and v.

Sample Input

3 5

Sample Output

2 -1

Explanation

2*3 - 1*5 = 1.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll a, b, x, y;

    cin>>a>>b;
    gcd(a, b, x, y);
    cout<<x<<' '<<y<<endl;
    return 0;
}
