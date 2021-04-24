import java.util.*;

class Program {
  public static int[] subarraySort(int[] array) {
    // Write your code here.
    int N=array.length, l=0, m, r=N-1;
    int min=Integer.MAX_VALUE, max=Integer.MIN_VALUE;

    while(l<N-1 && array[l]<=array[l+1]) {
      l++;
    }
    if(l==N-1) {
      return new int[]{-1, -1};
    }

    while(r>0 && array[r-1]<=array[r]) {
      r--;
    }

    for(m=l; m<=r; m++) {
      min = Math.min(min, array[m]);
      max = Math.max(max, array[m]);
    }

    while(l>0 && min<array[l-1]) {
      l--;
    }

    while(r<N-1 && max>array[r+1]) {
      r++;
    }

    return new int[] {l, r};
  }
}
