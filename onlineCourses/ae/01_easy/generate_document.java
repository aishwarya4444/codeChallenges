import java.util.*;

class Program {

  public boolean generateDocument(String characters, String document) {
    // Write your code here.
    Map<Character, Integer> freq = new HashMap<>();
    Integer count;

    for(Character ch: characters.toCharArray()) {
      freq.put(ch, freq.getOrDefault(ch, 0)+1);
    }
    for(char ch: document.toCharArray()) {
      count = freq.getOrDefault(ch, 0);
      if(count == 0) {
        return false;
      }
      freq.put(ch, count-1);
    }
    return true;
  }
}
