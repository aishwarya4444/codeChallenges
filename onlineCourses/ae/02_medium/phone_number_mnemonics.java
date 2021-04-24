import java.util.*;

class Program {

  public ArrayList<String> phoneNumberMnemonics(String phoneNumber) {
    // Write your code here.
    String[] letters = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int digit, L;
    ArrayList<String> res = new ArrayList<>();

    res.add("");
    for(char number: phoneNumber.toCharArray()) {
      digit = number-'0';
      L = res.size();
      while(L > 0) {
        L--;
        String prefix = res.remove(0);
        for(char letter: letters[digit].toCharArray()) {
          StringBuilder tmp = new StringBuilder(prefix);
          tmp.append(letter);
          res.add(tmp.toString());
        }
      }
    }

    return res;
  }
}
