import java.util.*;

class Program {
  public static List<List<String>> groupAnagrams(List<String> words) {
    // Write your code here.
    Map<String, List<String>> group = new HashMap<>();

    for(String word: words) {
      char[] letters = word.toCharArray();
      Arrays.sort(letters);
      String sortedWord = new String(letters);

      if(group.containsKey(sortedWord)) {
        group.get(sortedWord).add(word);
      } else {
        group.put(sortedWord, new ArrayList<String>(Arrays.asList(word)));
      }
    }

    return new ArrayList<>(group.values());
  }
}
