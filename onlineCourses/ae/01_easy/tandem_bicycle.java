import java.util.*;

class Program {

  public int tandemBicycle(int[] redShirtSpeeds, int[] blueShirtSpeeds, boolean fastest) {
    // Write your code here.
    // https://www.baeldung.com/java-sorting-arrays#descending-order
    int start, end, tmp, total=0, n, N=blueShirtSpeeds.length;

    Arrays.sort(redShirtSpeeds);
    Arrays.sort(blueShirtSpeeds);
    if(fastest) {
      start = 0; end = N-1;
      while(start<end) {
        tmp = blueShirtSpeeds[start];
        blueShirtSpeeds[start] = blueShirtSpeeds[end];
        blueShirtSpeeds[end] = tmp;
        start++;
        end--;
      }
    }

    for(n=0; n<N; n++) {
      total += Math.max(redShirtSpeeds[n], blueShirtSpeeds[n]);
    }

    return total;
  }
}
