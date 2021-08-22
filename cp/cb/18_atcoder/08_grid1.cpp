/*
https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int H, W;
int g[1000][1000];
const int mod = 1e9+7;

int main() {
    char ch;
    int h, w;

    cin>>H>>W;

    for(h=0; h<H; h++) {
        for(w=0; w<W; w++) {
            cin>>ch;
            g[h][w] = ch=='.' ? 0 : 1;
        }
    }

    g[0][0] = 1;
    for(h=1; h<H; h++) {
        if(g[h][0]) g[h][0] = 0;
        else g[h][0] = g[h-1][0];
    }

    for(w=1; w<W; w++) {
        if(g[0][w]) g[0][w] = 0;
        else g[0][w] = g[0][w-1];
    }

    for(h=1; h<H; h++) {
        for(w=1; w<W; w++) {
            if(g[h][w]) {
                g[h][w] = 0;
            } else {
                g[h][w] = (1LL*g[h-1][w] + g[h][w-1]) % mod;
            }
        }
    }

    cout<<g[H-1][W-1];

    return 0;
}
