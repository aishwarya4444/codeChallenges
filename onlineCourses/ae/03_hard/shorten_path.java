import java.util.*;

class Program {
  public static String shortenPath(String path) {
    // Write your code here;
    String[] tokens = path.split("/");
    List<String> st = new ArrayList<>();
    StringBuilder res = new StringBuilder();

    if(path.charAt(0) == '/') {
      st.add("");
    }
    for(String token: tokens) {
      if(token.equals(".") || token.equals("")) {
        continue;
      }
      if(token.equals("..")) {
        if(st.size()==0 || st.get(st.size()-1).equals("..")) {
          st.add(token);
        } else if(!st.get(st.size()-1).equals("")) {
          st.remove(st.size()-1);
        }
      } else {
        st.add(token);
      }
    }

    if(st.size()==1 && st.get(0).equals("")) {
      return "/";
    }
    return String.join("/", st);

  }
}

/*
import java.util.*;
import java.util.stream.Collectors;

class Program {
  public static String shortenPath(String path) {
    // Write your code here;
		String[] tokensArr = path.split("/");
		List<String> tokensList = Arrays.asList(tokensArr);
		List<String> tokens = tokensList
			.stream()
			.filter(token -> shouldKeep(token))
			.collect(Collectors.toList());
		List<String> st = new ArrayList<>();
		StringBuilder res = new StringBuilder();

		if(path.charAt(0) == '/') {
			st.add("");
		}
		for(String token: tokens) {
			if(token.equals(".") || token.equals("")) {
				continue;
			}
			if(token.equals("..")) {
				if(st.size()==0 || st.get(st.size()-1).equals("..")) {
					st.add(token);
				} else if(!st.get(st.size()-1).equals("")) {
					st.remove(st.size()-1);
				}
			} else {
				st.add(token);
			}
		}

		if(st.size()==1 && st.get(0).equals("")) {
			return "/";
		}
		return String.join("/", st);
  }

	private static boolean shouldKeep(String token) {
		return token != "" && token != ".";
	}
}

 */