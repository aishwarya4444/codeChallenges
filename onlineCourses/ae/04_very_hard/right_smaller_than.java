import java.util.*;

class Program {
  public static List<Integer> rightSmallerThan(List<Integer> array) {
    // Write your code here.
    // Average Case :
    // 		TC = O(n lg n)
    //		SC = O(n)
    //		n is size of array
    //		happens when tree is balanced
    // Worst Case :
    //		TC = O(n^2)
    //		SC = O(n)
    //		n is size of array
    //		happens when tree is like linked list
    int n, N=array.size();
    List<Integer> result = new ArrayList<>(array);
    if(N==0) {
      return result;
    }

    BST bst = new BST(array.get(N-1));

    result.set(N-1, 0);
    for(n=N-2; n>=0; n--) {
      bst.insert(n, array.get(n), result);
    }

    return result;
  }

  static class BST {
    int val;
    int leftSubtreeSize;
    BST left;
    BST right;

    BST(int val) {
      this.val = val;
      leftSubtreeSize = 0;
      left = null;
      right = null;
    }

    void insert(int idx, int val, List<Integer> result) {
      insertHelp(idx, val, result, 0);
    }

    void insertHelp(int idx, int val, List<Integer> result, int smallCountAtInsert) {
      if(val<this.val) {
        leftSubtreeSize++;
        if(this.left == null) {
          this.left = new BST(val);
          result.set(idx, smallCountAtInsert);
        } else {
          this.left.insertHelp(idx, val, result, smallCountAtInsert);
        }
      } else {
        smallCountAtInsert += leftSubtreeSize;
        if(val>this.val) {
          smallCountAtInsert++;
        }
        if(this.right == null) {
          this.right = new BST(val);
          result.set(idx, smallCountAtInsert);
        } else {
          this.right.insertHelp(idx, val, result, smallCountAtInsert);
        }
      }
    }
  }
}

/*
import java.util.*;

class Program {
  public static List<Integer> rightSmallerThan(List<Integer> array) {
    // Write your code here.
		// Average Case :
		// 		TC = O(n lg n)
		//		SC = O(n)
		//		n is size of array
		//		happens when tree is balanced
		// Worst Case :
		//		TC = O(n^2)
		//		SC = O(n)
		//		n is size of array
		//		happens when tree is like linked list
		int n, N=array.size();
		List<Integer> result = new ArrayList<>(array);
		if(N==0) {
			return result;
		}

		BST bst = new BST(N-1, array.get(N-1), 0);

		for(n=N-2; n>=0; n--) {
			bst.insert(n, array.get(n));
		}

		setSmallerCounts(bst, result);
    return result;
  }

	static void setSmallerCounts(BST bst, List<Integer> result) {
		if(bst == null) {
			return;
		}
		result.set(bst.idx, bst.smallCountAtInsert);
		setSmallerCounts(bst.left, result);
		setSmallerCounts(bst.right, result);
	}

	static class BST {
		int val;
		int idx;
		int leftSubtreeSize;
		int smallCountAtInsert;
		BST left;
		BST right;

		BST(int idx, int val, int smallCountAtInsert) {
			this.val = val;
			this.idx = idx;
			leftSubtreeSize = 0;
			this.smallCountAtInsert = smallCountAtInsert;
			left = null;
			right = null;
		}

		void insert(int idx, int val) {
			insertHelp(idx, val, 0);
		}

		void insertHelp(int idx, int val, int smallCountAtInsert) {
			if(val<this.val) {
				leftSubtreeSize++;
				if(this.left == null) {
					this.left = new BST(idx, val, smallCountAtInsert);
				} else {
					this.left.insertHelp(idx, val, smallCountAtInsert);
				}
			} else {
				smallCountAtInsert += leftSubtreeSize;
				if(val>this.val) {
					smallCountAtInsert++;
				}
				if(this.right == null) {
					this.right = new BST(idx, val, smallCountAtInsert);
				} else {
					this.right.insertHelp(idx, val, smallCountAtInsert);
				}
			}
		}
	}
}

 */