import java.util.*;

class Program {
  public static List<Integer[]> diskStacking(List<Integer[]> disks) {
    // Write your code here.
    int i, j, N=disks.size(), maxIdx=0;
    int[] dp = new int[N];
    int[] seq = new int[N];

    disks.sort((d1, d2) -> d1[2].compareTo(d2[2]));
    Arrays.fill(seq, -1);

    for(i=0; i<N; i++) {
      dp[i] = disks.get(i)[2];
    }

    for(i=1; i<N; i++) {
      Integer[] top = disks.get(i);
      for(j=0; j<i; j++) {
        Integer[] down = disks.get(j);
        if(down[0]<top[0] && down[1]<top[1] && down[2]<top[2]) {
          if(dp[i] <= dp[j]+top[2]) {
            seq[i] = j;
            dp[i] = dp[j]+top[2];
          }
        }
      }

      if(dp[i] >= dp[maxIdx]) {
        maxIdx = i;
      }
    }

    return buildSeq(disks, seq, maxIdx);
  }

  public static List<Integer[]> buildSeq(List<Integer[]> disks, int[] seq, int idx) {
    List<Integer[]> res = new ArrayList<Integer[]>();

    while(idx >= 0) {
      res.add(0, disks.get(idx));
      idx = seq[idx];
    }

    return res;
  }
}
