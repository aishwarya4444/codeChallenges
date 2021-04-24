import java.util.*;

class Program {

  public int minimumWaitingTime(int[] queries) {
    // Write your code here.
    int query, remainingQueries, result=0, n, N=queries.length;
    Arrays.sort(queries);

    for(n=0; n<N; n++) {
      query = queries[n];
      remainingQueries = N-1-n;
      result += query*remainingQueries;
    }
    return result;
  }
}
