import java.util.*;

class Tags {
  String str;
  int open;
  int close;
  Tags(String str, int open, int close) {
    this.str = str;
    this.open = open;
    this.close = close;
  }
}

class Program {

  public ArrayList<String> generateDivTags(int numberOfTags) {
    // Write your code here.
    ArrayList<String> result = new ArrayList<>();
    Queue<Tags> q = new LinkedList<>();

    q.add(new Tags("", 0, 0));
    while(q.size() > 0) {
      Tags tags = q.poll();
      if(tags.open==numberOfTags && tags.close==numberOfTags) {
        result.add(tags.str);
      } else {
        if(tags.open<numberOfTags) {
          q.add(new Tags(tags.str+"<div>", tags.open+1, tags.close));
        }
        if(tags.open>tags.close) {
          q.add(new Tags(tags.str+"</div>", tags.open, 1+tags.close));
        }
      }
    }

    return result;
  }
}
