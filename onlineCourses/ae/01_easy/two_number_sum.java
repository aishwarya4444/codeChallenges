import java.util.*;

class Program {
  public static int[] twoNumberSum(int[] array, int targetSum) {
    // Write your code here.
    int n, N=array.length;
    Set<Integer> nums = new HashSet<>();

    for(n=0; n<N; n++) {
      if( nums.contains(targetSum-array[n]) ) {
        return new int[] {array[n], targetSum-array[n]};
      } else {
        nums.add(array[n]);
      }
    }
    return new int[0];
  }
}

/*
import java.util.*;

class Program {
  public static int[] twoNumberSum(int[] array, int targetSum) {
    // Write your code here.
		int N=array.length, l=0, r=N-1;

		Arrays.sort(array);

		while(l<r) {
			if(array[l]+array[r] == targetSum) {
				return new int[] {array[l], array[r]};
			}

			if(array[l]+array[r] < targetSum) {
				l++;
			} else {
				r--;
			}
		}
    return new int[0];
  }
}
 */