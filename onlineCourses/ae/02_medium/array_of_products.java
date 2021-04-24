import java.util.*;

class Program {
  public int[] arrayOfProducts(int[] array) {
    // Write your code here.
    int n, N=array.length, prod;
    int[] result = new int[N];

    // Arrays.fill(result, 1);

    for(n=0, prod=1; n<N; n++) {
      result[n] = prod;
      prod *= array[n];
    }

    for(n=N-1, prod=1; n>=0; n--) {
      result[n] *= prod;
      prod *= array[n];
    }
    return result;
  }
}
