import java.util.*;

class Program {
  public static int longestPeak(int[] array) {
    // Write your code here.
    int n, N=array.length, left, right, length=0;
    boolean isPeak;

    for(n=1; n<=N-2; n++) {
      isPeak = array[n-1]<array[n] && array[n]>array[n+1];
      if(!isPeak) {
        continue;
      }

      left = n-1;
      while(left-1>=0 && array[left-1]<array[left]) {
        left--;
      }

      right = n+1;
      while(right+1<=N-1 && array[right]>array[right+1]) {
        right++;
      }

      length = Math.max(length, right-left+1);
      n = right;
    }

    return length;
  }
}
