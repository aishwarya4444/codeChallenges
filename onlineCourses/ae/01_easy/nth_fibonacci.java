import java.util.*;

class Program {
  public static int getNthFib(int n) {
    // Write your code here.
    int a=0, b=1, c=a+b;
    if(n<0) {
      return -1;
    }
    if(n==1) {
      return a;
    }
    if(n==2) {
      return b;
    }
    while(n>2) {
      n--;
      c = a+b;
      a = b;
      b = c;
    }
    return c;
  }
}
