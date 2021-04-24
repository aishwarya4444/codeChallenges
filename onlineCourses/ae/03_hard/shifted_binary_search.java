import java.util.*;

class Program {
  public static int shiftedBinarySearch(int[] array, int target) {
    // Write your code here.
    int l=0, m, r=array.length-1;

    while(l<=r) {
      m = l+(r-l)/2;
      if(array[m]==target) {
        return m;
      }

      if(array[l]==array[m] && array[m]==array[r]) {
        l++;
        r--;
      } else if(array[l]<=array[m]) {
        if(array[l]<=target && target<array[m]) {
          r = m-1;
        } else {
          l = m+1;
        }
      } else {
        if(array[m]<target && target<=array[r]) {
          l = m+1;
        } else {
          r = m-1;
        }
      }
    }

    return -1;
  }
}
