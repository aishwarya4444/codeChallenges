/*
https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Box {
    int x, y, z;
};

struct cmpBox {
    bool operator()(const Box &b1, const Box &b2) {
        return b1.x*b1.y < b2.x*b2.y;
    }
};

int main() {
    int t, n, l, w, h;

    cin>>t;

    while(t--) {
        cin>>n;

        vector<Box> boxes;

        while(n--) {
            cin>>l>>w>>h;
            boxes.push_back({min(w,h), max(w,h), l});
            boxes.push_back({min(l,h), max(l,h), w});
            boxes.push_back({min(l,w), max(l,w), h});
        }

        sort(boxes.begin(), boxes.end(), cmpBox());

        int B = boxes.size();
        vector<int> dp(B, 0);
        int maxH = boxes[0].z;

        for(int i=0; i<B; i++) {
            dp[i] = boxes[i].z;
            for(int j=0; j<i; j++) {
                if(boxes[j].x<boxes[i].x && boxes[j].y<boxes[i].y && dp[i]<dp[j]+boxes[i].z) {
                    dp[i] = dp[j]+boxes[i].z;
                    maxH = max(maxH, dp[i]);
                }
            }
        }
        cout<<maxH<<endl;

    }

    return 0;

}
