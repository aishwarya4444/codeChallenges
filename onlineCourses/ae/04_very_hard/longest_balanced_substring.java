import java.util.*;

class Program {
  public int longestBalancedSubstring(String string) {
    // Write your code here.
    int open, close, n, N=string.length(), len=0;

    open=0;
    close=0;
    for(n=0; n<N; n++) {
      if(string.charAt(n)=='(') {
        open++;
      } else {
        close++;
      }

      if(open==close) {
        len = Math.max(len, open*2);
      } else if(close>open) {
        open = 0;
        close = 0;
      }
    }

    open=0;
    close=0;
    for(n=N-1; n>=0; n--) {
      if(string.charAt(n)=='(') {
        open++;
      } else {
        close++;
      }

      if(open==close) {
        len = Math.max(len, open*2);
      } else if(open>close) {
        open = 0;
        close = 0;
      }
    }

    return len;
  }
}
