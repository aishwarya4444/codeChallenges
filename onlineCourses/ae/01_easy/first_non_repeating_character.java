import java.util.*;

class Program {

  public int firstNonRepeatingCharacter(String string) {
    // Write your code here.
    Map<Character, Integer> count = new HashMap<>();
    int n, N=string.length();

    for(char ch: string.toCharArray()) {
      count.put(ch, count.getOrDefault(ch, 0)+1);
    }

    for(n=0; n<N; n++) {
      if(count.get(string.charAt(n))==1) {
        return n;
      }
    }
    return -1;
  }
}
