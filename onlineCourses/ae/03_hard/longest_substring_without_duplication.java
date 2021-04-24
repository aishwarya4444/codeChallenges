import java.util.*;

class Program {
  public static String longestSubstringWithoutDuplication(String str) {
    // Write your code here
    Map<Character, Integer> pos = new HashMap<>();
    int start=0, end=0, N=str.length();
    int maxLen=0, begin=0;

    for(end=0; end<N; end++) {
      if(pos.containsKey(str.charAt(end))) {
        start = Math.max(start, 1+pos.get(str.charAt(end)));
      }
      pos.put(str.charAt(end), end);
      if(maxLen < end-start+1) {
        maxLen = end-start+1;
        begin = start;
      }
    }
    return str.substring(begin, begin+maxLen);
  }
}
