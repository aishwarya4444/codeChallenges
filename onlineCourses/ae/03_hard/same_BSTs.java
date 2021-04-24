import java.util.*;

class Program {
  public static boolean sameBsts(List<Integer> arrayOne, List<Integer> arrayTwo) {
    // Write your code here.
    // TC = O(n^2) .. where n is number of nodes in array
    // SC = O(d) .... where d is depth of BST
    return isSame(arrayOne, arrayTwo, 0, 0, Integer.MIN_VALUE, Integer.MAX_VALUE);
  }

  private static boolean isSame(List<Integer> a1, List<Integer> a2, int i1, int i2, int min, int max) {
    if(i1==-1 || i2==-1) {
      return i1==i2;
    }

    if(a1.get(i1).intValue() != a2.get(i2).intValue()) {
      return false;
    }

    int l1 = getNextSmall(a1, i1, min);
    int l2 = getNextSmall(a2, i2, min);
    int r1 = getNextBig(a1, i1, max);
    int r2 = getNextBig(a2, i2, max);
    int num = a1.get(i1);

    boolean isLeftSame = isSame(a1, a2, l1, l2, min, num);
    boolean isRightSame = isSame(a1, a2, r1, r2, num, max);

    return isLeftSame && isRightSame;
  }

  private static int getNextSmall(List<Integer> ar, int i, int min) {
    for(int n=1+i; n<ar.size(); n++) {
      if(ar.get(i).intValue()>ar.get(n).intValue() && ar.get(n).intValue()>=min) {
        return n;
      }
    }
    return -1;
  }

  private static int getNextBig(List<Integer> ar, int i, int max) {
    for(int n=1+i; n<ar.size(); n++) {
      if(ar.get(i).intValue()<ar.get(n).intValue() && ar.get(n).intValue()<max) {
        return n;
      }
    }
    return -1;
  }
}
