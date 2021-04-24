import java.util.*;

class Program {
  // O(w^2 * h) time | O(w) space - where w and h
  // are the width and height of the input array
  public double[] waterfallStreams(double[][] array, int source) {
    double[] rowAbove = array[0];
    // Well use -1 to represent water, since 1 is used for a block.
    rowAbove[source] = -1;

    for (int row = 1; row < array.length; row++) {
      double[] currentRow = array[row];
      for (int idx = 0; idx < rowAbove.length; idx++) {
        double valueAbove = rowAbove[idx];
        boolean hasWaterAbove = valueAbove < 0;
        boolean hasBlock = currentRow[idx] == 1.0;

        if (!hasWaterAbove) {
          continue;
        }

        if (!hasBlock) {
          // If there is no block in the current column, move the water down.
          currentRow[idx] += valueAbove;
          continue;
        }

        double splitWater = valueAbove / 2;
        // Move water right.
        int rightIdx = idx;
        while (rightIdx + 1 < rowAbove.length) {
          rightIdx += 1;
          if (rowAbove[rightIdx] == 1.0) { // if there is a block in the way
            break;
          } if (currentRow[rightIdx] != 1) { // if there is no block below us
            currentRow[rightIdx] += splitWater;
            break;
          }
        }

        // Move water left.
        int leftIdx = idx;
        while (leftIdx - 1 >= 0) {
          leftIdx -= 1;
          if (rowAbove[leftIdx] == 1.0) { // if there is a block in the way
            break;
          }
          if (currentRow[leftIdx] != 1.0) { // if there is no block below us
            currentRow[leftIdx] += splitWater;
            break;
          }
        }
      }

      rowAbove = currentRow;
    }

    double[] finalPercentages = new double[rowAbove.length];
    for (int idx = 0; idx < rowAbove.length; idx++) {
      double num = rowAbove[idx];
      if (num == 0) {
        finalPercentages[idx] = num;
      } else {
        finalPercentages[idx] = (num * -100);
      }
    }
    return finalPercentages;
  }
}
