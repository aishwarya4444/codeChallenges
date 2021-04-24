import java.util.*;

class Program {
  // Do not edit the class below except for the
  // populateSuffixTrieFrom and contains methods.
  // Feel free to add new properties and methods
  // to the class.
  static class TrieNode {
    Map<Character, TrieNode> children = new HashMap<Character, TrieNode>();
  }

  static class SuffixTrie {
    TrieNode root = new TrieNode();
    char endSymbol = '*';

    public SuffixTrie(String str) {
      populateSuffixTrieFrom(str);
    }

    public void populateSuffixTrieFrom(String str) {
      // Write your code here.
      for(int i=0; i<str.length(); i++) {
        TrieNode node = root;
        for(int j=i; j<str.length(); j++) {
          char letter = str.charAt(j);
          if(!node.children.containsKey(letter)) {
            TrieNode newNode = new TrieNode();
            node.children.put(letter, newNode);
          }
          node = node.children.get(letter);
        }
        node.children.put(endSymbol, null);
      }
    }

    public boolean contains(String str) {
      // Write your code here.
      TrieNode node = root;
      for(char ch: str.toCharArray()) {
        if(!node.children.containsKey(ch)) {
          return false;
        }
        node = node.children.get(ch);
      }
      return node.children.containsKey(endSymbol);
    }
  }
}
