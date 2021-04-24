import java.util.*;

class Program {

  // O(d * (n + b)) time | O(n + b) space - where n is the length of the input array,
  // d is the max number of digits, and b is the base of the numbering system used
  public ArrayList<Integer> radixSort(ArrayList<Integer> array) {
    if (array.size() == 0) {
      return array;
    }

    int maxNumber = Collections.max(array);
    int digit = 0;
    while ((maxNumber / Math.pow(10, digit)) > 0) {
      countingSort(array, digit); digit += 1;
    }

    return array;
  }

  public void countingSort(ArrayList<Integer> array, int digit) {
    int[] sortedArray = new int[array.size()];
    int[] countArray = new int[10];

    int digitColumn = (int) Math.pow(10, digit);
    for (int num : array) {
      int countIndex = (num / digitColumn) % 10; countArray[countIndex] += 1;
    }

    for (int idx = 1; idx < 10; idx++) {
      countArray[idx] += countArray[idx - 1];
    }

    for (int idx = array.size() - 1; idx > -1; idx--) {
      int countIndex = (array.get(idx) / digitColumn) % 10;
      countArray[countIndex] -= 1;
      int sortedIndex = countArray[countIndex];
      sortedArray[sortedIndex] = array.get(idx);
    }

    for (int idx = 0; idx < array.size(); idx++) {
      array.set(idx, sortedArray[idx]);
    }
  }
}
