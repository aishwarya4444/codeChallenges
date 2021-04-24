import java.util.*;

class Program {

  public int nonConstructibleChange(int[] coins) {
    // Write your code here.
    int change=0;

    Arrays.sort(coins);

    for(int coin: coins) {
      if(coin>1+change) {
        break;
      }
      change += coin;
    }
    return 1+change;
  }
}
