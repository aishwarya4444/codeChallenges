import java.util.*;

class Program {
  public int indexEqualsValue(int[] array) {
    // Write your code here.
    int lb=0, mid, ub=array.length-1, res=-1;

    while(lb<=ub) {
      mid = lb+(ub-lb)/2;
      if(array[mid]==mid) {
        res = mid;
        ub = mid-1;
      } else if(mid<array[mid]) {
        ub = mid-1;
      } else {
        lb = mid+1;
      }
    }

    return res;
  }
}

/*
import java.util.*;

class Program {
  public int indexEqualsValue(int[] array) {
    // Write your code here.
		// O(lg n) time | O(1) space
		int lb=0, mid, ub=array.length-1;

		while(lb<=ub) {
			mid = lb+(ub-lb)/2;
			if(array[mid]<mid) {
				lb = mid+1;
			} else if(mid==array[mid] && mid==0) {
				return mid;
			} else if(mid==array[mid] && array[mid-1]<(mid-1)) {
				return mid;
			} else {
				ub = mid-1;
			}
		}

    return -1;
  }
}

 */