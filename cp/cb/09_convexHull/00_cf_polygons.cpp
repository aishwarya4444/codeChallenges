/*
https://codeforces.com/problemset/problem/166/b

Sanyam Solution
https://codeforces.com/contest/166/submission/71482985

https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
pn = last point of hull
pi = in between point of hull
p1 = start point of hull


upper half of convex hull
                 pn
               `
             `
           `
         `
      pi-----------
      .
     .
    .
   .
  .
 p1----------------


lower half of convex hull
                 pn
                 `
                `
               `
              `
            pi-----
           .
         .
       .
     .
   .
 p1----------------



upper hull => clock wise      => slope of (pn, pi) < (pi, p1)
lower hull => anti clock wise => slope of (pn, pi) > (pi, p1)
collinear  =>                    slope of (pn, pi) = (pi, p1)


upper hull => clock wise case
slope of (pn, pi) < (pi, p1) .... let (p1, pi, pn) = (a, b, c)
(c.y - b.y)/(c.x - b.x) < (a.y - b.y)/(a.x - b.x)
(c.y - b.y)*(a.x - b.x) < (c.x - b.x)*(a.y - b.y)

cy.ax - cy.bx - by.ax + by.bx < cx.ay - cx.by - bx.ay + bx.by
cy.ax - cy.bx - by.ax < cx.ay - cx.by - bx.ay
ax(cy - by) - cy.bx < cx(ay - by) - bx.ay
ax(cy - by) + bx(ay - cy) + cx(by - ay) < 0
ax(by - cy) + bx(cy - ay) + cx(ay - by) > 0
*/

struct point {
    ll x;
    ll y;
    // ll is used because overflow can happen during + - *
};

// used for sort() and set<>
bool operator < (const point &p1, const point &p2) {
    if(p1.x == p2.x) {
        return p1.y<p2.y;
    }
    return p1.x<p2.x;
}

set<point> hull;
vector<point> a, b;
int n, m;

bool isClockWise(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool isAntiClockWise(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool isCollinear(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}

void convexHull() {
    vector<point> lo, up;

    n = a.size();
    sort(a.begin(), a.end());
    point p1=a[0], pn=a.back(), pi;

    lo.push_back(p1);
    up.push_back(p1);

    for(int i=1; i<n; i++) {
        pi = a[i];

        // upper half of convex hull
        // if(i==n-1 || isClockWise(p1, pi, pn)) {
        // we use !isAntiClockWise() to check for collinear condition also
        if(i==n-1 || !isAntiClockWise(p1, pi, pn)) {
            while(up.size()>1 && isAntiClockWise(up[up.size()-2], up.back(), pi)) {
                up.pop_back();
            }
            up.push_back(pi);
        }

        // lower half of convex hull
        // if(i==n-1 || isAntiClockWise(p1, pi, pn)) {
        // we use !isClockWise() to check for collinear condition also
        if(i==n-1 || !isClockWise(p1, pi, pn)) {
            while(lo.size()>1 && isClockWise(lo[lo.size()-2], lo.back(), pi)) {
                lo.pop_back();
            }
            lo.push_back(pi);
        }
    }

    for(auto p: lo) {
        hull.insert(p);
    }

    for(auto p: up) {
        hull.insert(p);
    }
}

int main()
{
    ll x, y;

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x>>y;
        a.push_back({x, y});
    }

    cin>>m;
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        a.push_back({x, y});
        b.push_back({x, y});
    }

    convexHull();

    for(auto p: b) {
        if(hull.count(p)) {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";

    return 0;
}

