import java.util.*;

class Program {
  public static List<String> boggleBoard(char[][] board, String[] words) {
    // Write your code here.
    int r, c, R=board.length, C=board[0].length;
    Trie trie = new Trie();
    Set<String> found = new HashSet<String>();
    int[][] dirs = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    boolean[][] visited = new boolean[R][C];
    List<String> result = new ArrayList<String>();

    for(String word: words) {
      trie.add(word);
    }

    for(r=0; r<R; r++) {
      for(c=0; c<C; c++) {
        dfs(r, c, R, C, visited, board, found, dirs, trie.root);
      }
    }

    result.addAll(found);
    return result;
  }

  static void dfs(int r, int c, int R, int C, boolean[][] visited, char[][] board, Set<String> found, int[][] dirs, TrieNode node) {
    int row, col;
    char letter = board[r][c];

    if(!node.children.containsKey(letter)) {
      return;
    }

    node = node.children.get(letter);
    visited[r][c] = true;
    if(node.children.containsKey('*')) {
      found.add(node.word);
    }

    for(int[] dir: dirs) {
      row = r+dir[0];
      col = c+dir[1];
      if(row<0 || row>=R || col<0 || col>=C || visited[row][col]) {
        continue;
      }
      dfs(row, col, R, C, visited, board, found, dirs, node);
    }
    visited[r][c] = false;
  }

  static class TrieNode {
    Map<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    String word = "";
  }

  static class Trie {
    TrieNode root;
    char endSymbol;

    public Trie() {
      this.root = new TrieNode();
      this.endSymbol = '*';
    }

    public void add(String str) {
      TrieNode node = root;
      for(char ch: str.toCharArray()) {
        if(!node.children.containsKey(ch)) {
          TrieNode newNode = new TrieNode();
          node.children.put(ch, newNode);
        }
        node = node.children.get(ch);
      }
      node.children.put(endSymbol, null);
      node.word = str;
    }
  }
}
