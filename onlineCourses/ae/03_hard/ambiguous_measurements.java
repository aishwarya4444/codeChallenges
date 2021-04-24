import java.util.*;

class Program {

  public boolean ambiguousMeasurements(int[][] measuringCups, int low, int high) {
    // Write your code here.
    // O(low*high*n) time | O(low*high) space
    HashMap<String, Boolean> mem = new HashMap<String, Boolean>();
    return canMeasureInRange(measuringCups, low, high, mem);
  }

  public boolean canMeasureInRange(int[][] cups, int low, int high, HashMap<String, Boolean> mem) {
    String memKey = createHashableKey(low, high);

    if(mem.containsKey(memKey)) {
      return mem.get(memKey);
    }

    if(low<=0 && high<=0) {
      return false;
    }

    boolean canMeasure = false;
    for(int[] cup: cups) {
      int cupLow = cup[0];
      int cupHigh = cup[1];

      if(low<=cupLow && cupHigh<=high) {
        canMeasure = true;
        break;
      }

      int newLow = Math.max(0, low-cupLow);
      int newHigh = Math.max(0, high-cupHigh);
      canMeasure = canMeasureInRange(cups, newLow, newHigh, mem);
      if(canMeasure) break;
    }

    mem.put(memKey, canMeasure);
    return canMeasure;
  }

  public String createHashableKey(int low, int high) {
    return String.valueOf(low) + ":" + String.valueOf(high);
  }
}
