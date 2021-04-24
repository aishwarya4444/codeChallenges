import java.util.*;

class Program {
  public String runLengthEncoding(String string) {
    // Write your code here.
    StringBuilder result = new StringBuilder();
    int n, N=string.length(), len=1;

    for(n=1; n<N; n++) {
      char curr = string.charAt(n), prev = string.charAt(n-1);

      if(curr!=prev || len==9) {
        result.append(Integer.toString(len));
        result.append(prev);
        len = 0;
      }
      len++;
    }

    result.append(Integer.toString(len));
    result.append(string.charAt(N-1));

    return result.toString();
  }
}
