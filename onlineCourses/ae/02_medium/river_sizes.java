import java.util.*;

class Pair {
  int first;
  int second;
  Pair(int f, int s) {
    first = f;
    second = s;
  }
}

class Program {
  private static int R;
  private static int C;
  private static List<Pair> dirs;

  private static void populateDirs() {
    dirs = new ArrayList<>();
    dirs.add(new Pair(-1, 0));
    dirs.add(new Pair(0, 1));
    dirs.add(new Pair(1, 0));
    dirs.add(new Pair(0, -1));
  }

  private static boolean outsideMatrix(int row, int col, int[][] matrix) {
    return (row<0 || row>=R || col<0 || col>=C);
  }

  private static int dfs(int row, int col, int[][] matrix, boolean[][] visited) {
    if(outsideMatrix(row, col, matrix) || visited[row][col] || matrix[row][col] == 0) {
      return 0;
    }

    int size = 1;

    visited[row][col] = true;
    for(Pair dir: dirs) {
      size += dfs(row+dir.first, col+dir.second, matrix, visited);
    }

    return size;
  }

  public static List<Integer> riverSizes(int[][] matrix) {
    // Write your code here.
    int row, col;
    List<Integer> sizes = new ArrayList<>();

    R = matrix.length;
    C = matrix[0].length;
    populateDirs();

    boolean[][] visited = new boolean[R][C];

    for(row=0; row<R; row++) {
      for(col=0; col<C; col++) {
        if(visited[row][col]) {
          continue;
        }
        if(matrix[row][col] == 1) {
          sizes.add(dfs(row, col, matrix, visited));
        }
      }
    }
    return sizes;
  }
}

/*
import java.util.*;

class Program {
	private static int R;
	private static int C;
	private static final int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	private static boolean outsideMatrix(int row, int col, int[][] matrix) {
		return (row<0 || row>=R || col<0 || col>=C);
	}

	private static int dfs(int row, int col, int[][] matrix, boolean[][] visited) {
		if(outsideMatrix(row, col, matrix) || visited[row][col] || matrix[row][col] == 0) {
			return 0;
		}

		int size = 1;

		visited[row][col] = true;
		for(int[] dir: dirs) {
			size += dfs(row+dir[0], col+dir[1], matrix, visited);
		}

		return size;
	}

  public static List<Integer> riverSizes(int[][] matrix) {
    // Write your code here.
		int row, col;
		List<Integer> sizes = new ArrayList<>();

		R = matrix.length;
		C = matrix[0].length;

		boolean[][] visited = new boolean[R][C];

		for(row=0; row<R; row++) {
			for(col=0; col<C; col++) {
				if(visited[row][col]) {
					continue;
				}
				if(matrix[row][col] == 1) {
					sizes.add(dfs(row, col, matrix, visited));
				}
			}
		}
    return sizes;
  }
}
 */