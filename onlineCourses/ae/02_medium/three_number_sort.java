import java.util.*;

class Program {
  public int[] threeNumberSort(int[] array, int[] order) {
    // Write your code here.
    int left=0, mid=0, right=array.length-1;

    while(mid<=right) {
      if(array[mid]==order[0]) {
        swap(left, mid, array);
        left++;
        mid++;
      } else if(array[mid]==order[1]) {
        mid++;
      } else if(array[mid]==order[2]) {
        swap(mid, right, array);
        right--;
      }
    }

    return array;
  }

  private static void swap(int i, int j, int[] array) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
}

/*
import java.util.*;

class Program {
  public int[] threeNumberSort(int[] array, int[] order) {
    // Write your code here.
    HashMap<Integer, Integer> freq = new HashMap<>();
		int i=0, count;

		if(array.length == 0) {
			return array;
		}

		for(int num: array) {
			freq.put(num, freq.getOrDefault(num, 0)+1);
		}

		for(int num: order) {
			count = freq.getOrDefault(num, 0);
			while(count>0) {
				count--;
				array[i] = num;
				i++;
			}
		}

    return array;
  }
}
 */