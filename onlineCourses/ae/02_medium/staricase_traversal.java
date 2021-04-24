import java.util.*;

class Program {

  public int staircaseTraversal(int height, int maxSteps) {
    // Write your code here.
    // O(height * maxSteps) time and O(height) space
    int[] waysToTop = new int[height+1];

    waysToTop[0] = 1;
    waysToTop[1] = 1;

    for(int h=2; h<=height; h++) {
      for(int step=1; step<=maxSteps && step<=h; step++) {
        waysToTop[h] += waysToTop[h-step];
      }
    }

    return waysToTop[height];
  }
}
