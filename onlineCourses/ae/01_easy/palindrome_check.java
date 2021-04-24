import java.util.*;

class Program {
  public static boolean isPalindrome(String str) {
    // Write your code here.
    int l=0, r=str.length()-1;

    str = str.toLowerCase();
    while(l<r) {
      while(str.charAt(l)==' ') {
        l++;
      }
      while(str.charAt(r)==' ') {
        r--;
      }
      if(str.charAt(l)!=str.charAt(r)) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
}
