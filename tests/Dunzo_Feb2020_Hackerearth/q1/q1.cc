#include<iostream>
#include<vector>
#include<queue>

#define LLI long long int
using namespace std;


vector<vector<int> > a, d;
vector<bool> visited;
vector<pair<int, int> > dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int N, M, T;

bool isMovePossible(int r, int c) {
  return r>=0 && r<N && c>=0 && c<M;
}

void bfs() {
  queue<int> q;
  int day = 0, r, c, row, col, thickness, N, cell;

  if(a[0][0]>T) {
    cout<<"NO\n";
    return;
  }

  q.push(0);
  while(q.size()) {
    N = q.size();

    day++;

    while(N--) {
      cell = q.front();
      q.pop();
      r = cell/M;
      c = cell%M;

      for(auto dir: dirs) {
        row = r+dir.first;
        col = c+dir.second;

        if(!isMovePossible(row, col) || visited[row*M + col]) {
          continue;
        }

        thickness = a[row][col] + day*d[row][col];
        if(thickness>T) {
          continue;
        }

        if(row == N-1 && col == M-1) {
          cout<<"YES\n";
          return;
        }

        q.push(row*M + col);
      }
    }
  }

  cout<<"NO\n";
}

int main() {
	int r, c;
	LLI t;
	char p;

	cin>>t;
	while(t--) {
	  cin>>N>>M>>T;

	  a = vector<vector<int> >(N, vector<int>(M, 0));
	  d = vector<vector<int> >(N, vector<int>(M, 0));
	  visited = vector<bool>(N*M, false);

	  // initial
	  for(r=0; r<N; r++) {
	    for(c=0; c<M; c++) {
	      cin>>a[r][c];
	    }
	  }

	  // rate
	  for(r=0; r<N; r++) {
	    for(c=0; c<M; c++) {
	      cin>>d[r][c];
	    }
	  }

	  bfs();

	  a.clear();
	  d.clear();
	  visited.clear();
	}

	return 0;
}
