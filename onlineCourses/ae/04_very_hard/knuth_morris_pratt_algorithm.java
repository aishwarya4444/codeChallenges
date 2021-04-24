import java.util.*;

class Program {
  public static boolean knuthMorrisPrattAlgorithm(String string, String substring) {
    // Write your code here.
    int[] pattern = buildPattern(substring);
    return doesMatch(string, substring, pattern);
  }

  private static int[] buildPattern(String sub) {
    int i, j, SUB=sub.length();
    int[] pattern = new int[SUB];

    Arrays.fill(pattern, -1);

    i = 1; // middle of string
    j = 0; // start of string
    while(i<SUB) {
      if(sub.charAt(i) == sub.charAt(j)) {
        pattern[i] = j;
        i++;
        j++;
      } else if(j>0) {
        j = 1+pattern[j-1];
      } else {
        i++;
      }
    }

    return pattern;
  }

  private static boolean doesMatch(String str, String sub, int[] pattern) {
    int i, j, STR=str.length(), SUB=sub.length();

    i = 0; // string
    j = 0; // substring
    while(i-j <= STR-SUB) {
      if(str.charAt(i) == sub.charAt(j)) {
        if(j+1 == SUB) {
          return true;
        }
        i++;
        j++;
      } else if(j>0) {
        j = 1+pattern[j-1];
      } else {
        i++;
      }
    }

    return false;
  }
}
