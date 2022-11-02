/*
https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

multiple source shortest path
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();

	    for(int r=0; r<n; r++) {
	        for(int c=0; c<n; c++) {
	            // put cost as INF if unreachable
	            if(matrix[r][c] == -1) matrix[r][c] = 1e9;
	            // for same node - cost is 0
	            // if(r==c) matrix[r][c] = 0;
	        }
	    }

	    // TC = O(n^3)
	    // SC = O(n^2)
	    for(int k=0; k<n; k++) {
	        for(int i=0; i<n; i++) {
    	        for(int j=0; j<n; j++) {
    	            if(matrix[i][j] > matrix[i][k]+matrix[k][j]) {
    	                matrix[i][j] = matrix[i][k]+matrix[k][j];
    	            }
    	        }
    	    }
	    }

	    // for same vertex .. cost to visit is zero
	    // if this cost is negative after Floyd Warshall algo runs
	    // then it means that negative cycle is present
	    for(int k=0; k<n; k++) {
	        if(matrix[k][k] < 0) {
	            // negative cycle is present
	        }
	    }

	    for(int r=0; r<n; r++) {
	        for(int c=0; c<n; c++) {
	            if(matrix[r][c] == 1e9) matrix[r][c] = -1;
	        }
	    }
	}
};
