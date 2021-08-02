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
*/

struct point {
    int x;
    int y;
    bool operator < (point &O) {
        if (O.x == x) return y < O.y;
        else return x < O.x;
    }
    bool operator == (point &O) {
        return (x == O.x && y == O.y);
    }

};

// struct cmpAsc {
//     bool operator()(const point &p1, const point &p2) {
//         if(p1.x == p2.x) {
//             return p1.y<p2.y;
//         }
//         return p1.x<p2.x;
//     }
// };

vector<point> a;
vector<point> b;
// set<point, cmpAsc()> b;
// set<point, cmpAsc()> hull;
map<pair<int, int>, int > hull;
int n, m;

// struct cmpEqual {
//     bool operator()(const point &p1, const point &p2) {
//         return p1.x==p2.x && p1.y==p2.y;
//     }
// };

bool isClockWise(point a, point b, point c) {
    return (c.y - b.y)*(a.x - b.x) < (c.x - b.x)*(a.y - b.y);
}

bool isAntiClockWise(point a, point b, point c) {
    return (c.y - b.y)*(a.x - b.x) > (c.x - b.x)*(a.y - b.y);
}

bool isCollinear(point a, point b, point c) {
    return (c.y - b.y)*(a.x - b.x) == (c.x - b.x)*(a.y - b.y);
}
bool cw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool ccw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
void convexHull() {
    vector<point> lo, up;
    sort(a.begin(), a.end());
    point p1=a[0], pn=a.back(), pi;

    lo.push_back(p1);
    up.push_back(p1);

    for(int i=1; i<n; i++) {
        pi = a[i];
        // if(i==n-1 || isClockWise(p1, pi, pn)) {
        //     if(up.size()>1 && !isClockWise(up[up.size()-2], up.back(), pn)) {
        //         up.pop_back();
        //     }
        //     up.push_back(pi);
        // }

        // if(i==n-1 || isAntiClockWise(p1, pi, pn)) {
        //     if(lo.size()>1 && !isAntiClockWise(lo[lo.size()-1], lo.back(), pn)) {
        //         lo.pop_back();
        //     }
        //     lo.push_back(pi);
        // }

        if (i == n - 1 || !ccw(p1, pi, pn)) {
            // p[i] is in the upper half
            while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], pi)) {
                up.pop_back();
            }
            up.push_back(pi);
        }
        if (i == n - 1 || !cw(p1, pi, pn)) {
            // p[i] is in the lower half
            while (lo.size() >= 2 && cw(lo[lo.size() - 2], lo[lo.size() - 1], pi)) {
                lo.pop_back();
            }
            lo.push_back(pi);
        }
    }

    for(auto p: a) {
        // hull.insert(p);
        hull[{p.x,p.y}]++;
    }

    for(auto p: b) {
        // hull.insert(p);
        hull[{p.x,p.y}]++;
    }
}

int main()
{
    int x, y;

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
        if(hull.count({p.x, p.y})) {
            cout<<"NO";
            return 0;
        }
    }

    for(auto p: hull) {
        cout<<p.first.first<<' '<<p.first.second<<endl;
    }

    cout<<"YES";

    return 0;
}
