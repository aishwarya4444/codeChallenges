import java.util.*;

class Program {

  public String reverseWordsInString(String string) {
    // Write your code here.
    char[] letters = string.toCharArray();
    int n=0, N=letters.length, l, r;

    while(n < N) {
      l = n;
      r = n;
      if(n<N && letters[n] == ' ') {
        n++;
        continue;
      }
      while(n<N && letters[n] != ' ') {
        n++;
      }
      r = n-1;
      reverse(letters, l, r);
    }

    reverse(letters, 0, N-1);

    return new String(letters);
  }

  private static void reverse(char[] letters, int l, int r) {
    while(l<r) {
      char tmp = letters[l];
      letters[l] = letters[r];
      letters[r] = tmp;
      l++;
      r--;
    }
  }
}
