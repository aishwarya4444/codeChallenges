// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int minimumDistance(int numRows, int numColumns, int **area)
{
    // WRITE YOUR CODE HERE
    vector<pair<int, int> > dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    queue<pair<int, int>> q;
    pair<int, int> cell;
    int n, x, y, r, c, level=0, R=numRows, C=numColumns;
    bool visited[R][C] = {false};
    // vector<vector<bool> > visited = vector<vector<bool> >(R, vector<bool>(C, false));
    visited[0][0] = true;
    q.push({0,0});
    if(area[0][0]==9) {
        return 0;
    }
    if(area[0][0]==0) {
        return -1;
    }
    while(q.size()) {
        n = q.size();
        level++;
        while(n--) {
            cell = q.front();
            q.pop();
            x = cell.first;
            y = cell.second;
            for(auto dir: dirs) {
                r = x+dir.first;
                c = y+dir.second;
                if(r>=0 && r<R && c>=0 && c<C && area[r][c] && !visited[r][c]) {
                    visited[r][c] = true;
                    if(area[r][c] == 9) {
                        return level;
                    }
                    q.push({r,c});
                }
            }
        }
    }
    
    return -1;
    
}
// FUNCTION SIGNATURE ENDS