import java.util.*;

class Program {

  public ArrayList<String> validIPAddresses(String string) {
    // Write your code here.
    int i, j, k, N=string.length();
    String[] ip = new String[]{"", "", "", ""};
    ArrayList<String> result = new ArrayList<String>();

    for(i=1; i<Math.min(4, N); i++) {
      ip[0] = string.substring(0, i);
      if(!isValid(ip[0])) {
        continue;
      }

      for(j=i+1; j<i+Math.min(N-i, 4); j++) {
        ip[1] = string.substring(i, j);
        if(!isValid(ip[1])) {
          continue;
        }

        for(k=j+1; k<j+Math.min(N-j, 4); k++) {
          ip[2] = string.substring(j, k);
          ip[3] = string.substring(k);
          if(!isValid(ip[2]) || !isValid(ip[3])) {
            continue;
          }

          result.add(joinIP(ip));
        }
      }
    }

    return result;
  }

  boolean isValid(String str) {
    int num = Integer.parseInt(str);

    if(num>255) {
      return false;
    }

    return str.length() == Integer.toString(num).length();
  }

  String joinIP(String[] ip) {
    StringBuilder sb = new StringBuilder();

    for(String part: ip) {
      sb.append(part);
      sb.append(".");
    }
    sb.deleteCharAt(sb.length()-1);

    return sb.toString();
  }
}
