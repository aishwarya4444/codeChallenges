/*
https://leetcode.com/problems/erect-the-fence/
*/

class Solution {
public:
    bool isClockWise(vector<int> a, vector<int> b, vector<int> c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) > 0;
    }

    bool isAntiClockWise(vector<int> a, vector<int> b, vector<int> c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) < 0;
    }

    bool isCollinear(vector<int> a, vector<int> b, vector<int> c) {
        return a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]) == 0;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> lo, up;

        int n = trees.size();
        sort(trees.begin(), trees.end());
        vector<int> p1=trees[0], pn=trees.back(), pi;

        lo.push_back(p1);
        up.push_back(p1);

        for(int i=1; i<n; i++) {
            pi = trees[i];

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

        trees.clear();

        for(auto tree: lo) {
            trees.push_back(tree);
        }

        for(auto tree: up) {
            if(find(trees.begin(), trees.end(), tree) == trees.end())
                trees.push_back(tree);
        }

        return trees;
    }
};