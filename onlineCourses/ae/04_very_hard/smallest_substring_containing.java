import java.util.*;

class Program {
  public static String smallestSubstringContaining(String bigString, String smallString) {
    // Write your code here.
    int start=0, end, match=0, B=bigString.length(), S=smallString.length(), len=B+1, begin=-1;
    Map<Character, Integer> freq = new HashMap<>();
    char letter;

    for(char ch: smallString.toCharArray()) {
      freq.put(ch, freq.getOrDefault(ch, 0) + 1);
    }

    for(end=0; end<B; end++) {
      letter = bigString.charAt(end);
      if(freq.containsKey(letter)) {
        freq.put(letter, freq.get(letter) - 1);
        if(freq.get(letter) >= 0) {
          match++;
        }
      }
      while(match == S) {
        if(len > end-start+1) {
          len = end-start+1;
          begin = start;
        }
        letter = bigString.charAt(start);
        if(freq.containsKey(letter)) {
          if(freq.get(letter) == 0) {
            match--;
          }
          freq.put(letter, freq.get(letter) + 1);
        }
        start++;
      }
    }
    return begin==-1 ? "" : bigString.substring(begin, begin+len);
  }
}
