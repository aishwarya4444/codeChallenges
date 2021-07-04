/*
https://codeforces.com/problemset/problem/219/C
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000007;

int main() {
    string colors;
    int n, k, count=0;
    char ch;

    cin>>n>>k;
    cin>>colors;

    if(k<=2) {
        int rA=0; // string is like ABAB...
        int rB=0; // string is like BABA...

        for(int i=0; i<n; i++) {
            ch = 'A'+(i%2);
            if(colors[i]!=ch) {
                rA++;
            }
        }

        for(int i=0; i<n; i++) {
            ch = 'A'+((i+1)%2);
            if(colors[i]!=ch) {
                rB++;
            }
        }

        if(rA<rB) {
            for(int i=0; i<n; i++) {
                ch = 'A'+(i%2);
                colors[i] = ch;
            }
            count = rA;
        } else {
            for(int i=0; i<n; i++) {
                ch = 'A'+((i+1)%2);
                colors[i] = ch;
            }
            count = rB;
        }
    } else {
        for(int i=1; i<n; i++) {
            if(colors[i-1]==colors[i]) {
                colors[i] = 'A';
                while(colors[i-1]==colors[i] || colors[i]==colors[i+1]) {
                    colors[i]++;
                }
                count++;
            }
        }
    }

    cout<<count<<'\n'<<colors;

    return 0;

}
