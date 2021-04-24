import java.util.*;

class Program {
  public static int[] mergeSort(int[] array) {
    // Write your code here.
    sort(array, 0, array.length-1);
    return array;
  }

  private static void sort(int[] array, int l, int r) {
    if(l<r) {
      int m = l+(r-l)/2;
      sort(array, l, m);
      sort(array, m+1, r);
      merge(array, l, m, r);
    }
  }

  private static void merge(int[] array, int l, int m, int r) {
    int n = l, n1, n2, N1 = m-l+1, N2 = r-m;
    int[] a1 = new int[N1];
    int[] a2 = new int[N2];

    for(n1=0; n1<N1; n1++, n++) {
      a1[n1] = array[n];
    }

    for(n2=0; n2<N2; n2++, n++) {
      a2[n2] = array[n];
    }

    n1 = 0;
    n2 = 0;
    n = l;
    while(n1<N1 && n2<N2) {
      if(a1[n1] < a2[n2]) {
        array[n] = a1[n1];
        n1++;
      } else {
        array[n] = a2[n2];
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
  }
}
