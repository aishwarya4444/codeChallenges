/*

[1] 2 eggs and N floors - https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
[2] k eggs and N floors - https://leetcode.com/problems/super-egg-drop/
https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand

https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
https://www.geeksforgeeks.org/egg-dropping-puzzle-with-2-eggs-and-k-floors/
*/

// k eggs and n floors
// [1] k.n.n TC solution
// [2] k.n.log n TC solution
class Solution {
public:
    int dp[101][10001];

    int solve(int eggs, int floors) {
        if(floors < 2) return floors;
        if(eggs == 1) return floors;

        if(dp[eggs][floors] != -1) {
            return dp[eggs][floors];
        }

        int drops = INT_MAX;
        // for(int f=1; f<=floors; f++) {
        //     int op1 = solve(eggs-1, f-1); // egg breaks
        //     int op2 = solve(eggs, floors-f); // egg does not break
        //     drops = min(drops, max(op1, op2));
        // }
        int lo=1, f, hi=floors;
        while(lo<=hi) {
            f = (lo+hi)/2;
            int op1 = solve(eggs-1, f-1); // egg breaks .. go down
            int op2 = solve(eggs, floors-f); // egg does not break .. go up
            drops = min(drops, max(op1, op2));
            if(op1<op2) { // op1<op2 .. and we need more in worst case
                lo = f+1; // so l=f+1 to gain more temp for worst case : upward
            } else {
                hi = f-1; // go down
            }
        }

        return dp[eggs][floors] = drops+1;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof dp);
        return solve(k, n);
    }
};

/*
min max logic and reason
https://www.youtube.com/watch?v=UvksR0hR9nA

if operation is in your control - take max
if operation is not in your control - take min

take min of all max operations for guaranteed winning/optimal solution
*/

class Solution {
public:
    int dp[3][1001];
    int solve(int eggs, int floors) {
        if(floors==0 || floors==1) return floors;

        if(eggs==1) return floors;

        if(dp[eggs][floors] != -1) {
            return dp[eggs][floors];
        }

        int moves = INT_MAX;

        for(int f=1; f<=floors; f++) {
            int choice2 = solve(eggs-1, f-1); // egg breaks + try for lesser floors
            int choice1 = solve(eggs, floors-f); // egg does not break + (F-f) floor left
            moves = min(moves, max(choice1, choice2));
        }

        return dp[eggs][floors] = 1+moves;
    }

    int twoEggDrop(int n) {
        // return floor(sqrt(2.0*n) + 0.5);
        memset(dp, -1, sizeof dp);
        return solve(2, n);
    }
};
