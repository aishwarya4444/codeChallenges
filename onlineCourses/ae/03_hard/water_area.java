import java.util.*;

class Program {
  public static int waterArea(int[] heights) {
    // Write your code here.
    int minHeight, water=0, n, N=heights.length;
    int[] left = new int[N];
    int[] right = new int[N];

    if(N<=2) {
      return water;
    }

    left[0] = heights[0];
    for(n=1; n<N; n++) {
      left[n] = Math.max(left[n-1], heights[n]);
    }

    right[N-1] = heights[N-1];
    for(n=N-2; n>=0; n--) {
      right[n] = Math.max(right[n+1], heights[n]);
    }

    for(n=1; n<=N-2; n++) {
      minHeight = Math.min(left[n-1], right[n+1]);
      water += Math.max(minHeight-heights[n], 0);
    }
    return water;
  }
}
