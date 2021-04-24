import java.util.*;

class Program {

  public int countInversions(int[] array) {
    // Write your code here.
    // O(n lg n) time and O(n) space
    return countSubArrayInversions(array, 0, array.length-1);
  }

  public int countSubArrayInversions(int[] array, int start, int end) {
    if(start >= end) {
      return 0;
    }

    int mid = start+(end-start)/2;
    int leftInv = countSubArrayInversions(array, start, mid);
    int rightInv = countSubArrayInversions(array, mid+1, end);
    int mergedArrayInv = mergeInversions(array, start, mid, end);

    return leftInv + rightInv + mergedArrayInv;
  }

  public int mergeInversions(int[] array, int start, int mid, int end) {
    int n, n1, n2, N1=mid-start+1, N2=end-mid;
    int[] a1 = new int[N1];
    int[] a2 = new int[N2];
    int inversions = 0;

    for(n=start, n1=0; n1<N1; n1++, n++) {
      a1[n1] = array[n];
    }

    for(n2=0; n2<N2; n2++, n++) {
      a2[n2] = array[n];
    }

    n1 = 0;
    n2 = 0;
    n = start;
    while(n1<N1 && n2<N2) {
      if(a1[n1] <= a2[n2]) {
        array[n] = a1[n1];
        n1++;
      } else {
        array[n] = a2[n2];
        inversions += N1-n1;
        n2++;
      }
      n++;
    }

    while(n1<N1) {
      array[n] = a1[n1];
      n++;
      n1++;
    }

    while(n2<N2) {
      array[n] = a2[n2];
      n++;
      n2++;
    }

    return inversions;
  }
}
