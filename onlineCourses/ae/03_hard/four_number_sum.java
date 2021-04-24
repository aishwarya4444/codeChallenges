import java.util.*;

class Program {
  public static List<Integer[]> fourNumberSum(int[] array, int targetSum) {
    // Write your code here.
    List<Integer[]> res = new ArrayList<>();
    int i, j, k, l, N=array.length, sum;

    Arrays.sort(array);
    for(i=0; i<N-3; i++) {
      if(i>0 && array[i]==array[i-1]) {
        continue;
      }
      for(j=i+1; j<N-2; j++) {
        if(j>i+1 && array[j]==array[j-1]) {
          continue;
        }
        k = j+1;
        l = N-1;
        while(k<l) {
          sum = array[i]+array[j]+array[k]+array[l];
          if(sum==targetSum) {
            Integer[] quad = {array[i], array[j], array[k], array[l]};
            res.add(quad);
            k++;
            l--;
            while(k<l && array[k]==array[k-1]) {
              k++;
            }
            while(k<l && array[l]==array[l+1]) {
              l--;
            }
          } else if(sum<targetSum) {
            k++;
          } else {
            l--;
          }
        }
      }
    }
    return res;
  }
}
