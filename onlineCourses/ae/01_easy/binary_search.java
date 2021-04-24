class Program {
  public static int binarySearch(int[] array, int target) {
    // Write your code here.
    int lb=0, ub=array.length-1, mid;

    while(lb<=ub) {
      mid = lb+(ub-lb)/2;
      if(array[mid]==target) {
        return mid;
      } else if(target<array[mid]) {
        ub = mid-1;
      } else {
        lb = mid+1;
      }
    }
    return -1;
  }
}
