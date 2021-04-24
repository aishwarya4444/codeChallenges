import java.util.*;

class Program {
  public static int[] searchForRange(int[] array, int target) {
    // Write your code here.
    int[] result = new int[2];

    result[0] = binarySearch(array, target, true);
    result[1] = binarySearch(array, target, false);

    return result;
  }

  private static int binarySearch(int[] array, int target, boolean findLeft) {
    int start=0, mid, end=array.length-1, index=-1;

    while(start<=end) {
      mid = start+(end-start)/2;
      if(array[mid]==target) {
        index = mid;
        if(findLeft) {
          end = mid-1;
        } else {
          start = mid+1;
        }
      } else if(array[mid]<target) {
        start = mid+1;
      } else {
        end = mid-1;
      }
    }

    return index;
  }
}
