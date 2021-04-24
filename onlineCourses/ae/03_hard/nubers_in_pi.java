import java.util.*;

class Program {
  public static int numbersInPi(String pi, String[] numbers) {
    // Write your code here.
    // TC = O(n^3 + m)
    // SC = O(n + m)
    // n is no of digits in pi and m is no of favourite numbers
    Set<String> set = new HashSet<>();
    Map<Integer, Integer> cache = new HashMap<>();

    for(String num: numbers) {
      set.add(num);
    }

    int minSpaces = getMinSpaces(pi, set, cache, 0);

    return minSpaces==Integer.MAX_VALUE ? -1 : minSpaces;
  }

  static int getMinSpaces(String pi, Set<String> set, Map<Integer, Integer> cache, int i) {
    if(i==pi.length()) {
      return -1;
    }

    if(cache.containsKey(i)) {
      return cache.get(i);
    }

    int minSpaces = Integer.MAX_VALUE;
    int n, N=pi.length();
    for(n=i; n<N; n++) {
      String prefix = pi.substring(i, n+1);
      if(set.contains(prefix)) {
        int minSpacesSuffix = getMinSpaces(pi, set, cache, n+1);
        if(minSpacesSuffix==Integer.MAX_VALUE) {
          minSpaces = Math.min(minSpaces, minSpacesSuffix);
        } else {
          minSpaces = Math.min(minSpaces, minSpacesSuffix+1);
        }
      }
    }
    cache.put(i, minSpaces);
    return cache.get(i);
  }
}
