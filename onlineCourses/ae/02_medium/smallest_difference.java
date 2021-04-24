import java.util.*;

class Program {
  public static int[] smallestDifference(int[] arrayOne, int[] arrayTwo) {
    // Write your code here.
    Arrays.sort(arrayOne);
    Arrays.sort(arrayTwo);

    int[] result = new int[2];
    int n1 = 0, n2 = 0, N1 = arrayOne.length, N2 = arrayTwo.length;
    int diff, minDiff = Integer.MAX_VALUE;

    while(n1<N1 && n2<N2) {
      diff = arrayOne[n1]-arrayTwo[n2];

      if(Math.abs(diff) < minDiff) {
        minDiff = Math.abs(diff);
        result = new int[]{arrayOne[n1], arrayTwo[n2]};
      }

      if(diff<0) {
        n1++;
      } else if(diff>0) {
        n2++;
      } else {
        return new int[]{arrayOne[n1], arrayTwo[n2]};
      }
    }

    return result;
  }
}

/*
import java.util.*;

class Program {
  public static int[] smallestDifference(int[] arrayOne, int[] arrayTwo) {
    // Write your code here.
    int[] result = new int[]{arrayOne[0], arrayTwo[0]};
		int diff, minDiff = Math.abs(arrayOne[0]-arrayTwo[0]);

		for(int val1: arrayOne) {
			for(int val2: arrayTwo) {
				diff = Math.abs(val1-val2);
				if(diff < minDiff) {
					minDiff = diff;
					result = new int[]{val1, val2};
				}
			}
		}

    return result;
  }
}
 */