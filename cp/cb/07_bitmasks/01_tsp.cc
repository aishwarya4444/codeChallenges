/*
https://www.youtube.com/watch?v=JE0JE8ce1V0
https://ide.codingblocks.com/s/3899

Kartik blog
https://codeforces.com/blog/entry/81516

TSP with very high N
https://codeforces.com/problemset/problem/1503/C

https://leetcode.com/problems/find-the-shortest-superstring/
https://leetcode.com/problems/find-the-shortest-superstring/discuss/194932/Travelling-Salesman-Problem

https://leetcode.com/problems/shortest-path-visiting-all-nodes/
*/

#include<iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int VISITED_ALL = (1<<n) -1;

int dp[16][4];


int  tsp(int mask,int pos){

	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++){

		if((mask&(1<<city))==0){

			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, newAns);
		}

	}

	return dp[mask][pos] = ans;
}

int main(){
    /* init the dp array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
	cout<<"Travelling Saleman Distance is "<<tsp(1,0);

return 0;
}
