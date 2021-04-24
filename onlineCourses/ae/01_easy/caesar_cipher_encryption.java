import java.util.*;

class Program {
  public static String caesarCypherEncryptor(String str, int key) {
    // Write your code here.
    StringBuilder sb = new StringBuilder();

    for(char ch: str.toCharArray()) {
      int num = (ch-'a'+key)%26+'a';
      sb.append((char)num);
    }
    return sb.toString();
  }
}
