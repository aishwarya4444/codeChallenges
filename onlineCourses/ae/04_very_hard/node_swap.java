import java.util.*;

class Program {
  // This is an input class. Do not edit.
  public static class LinkedList {
    public int value;
    public LinkedList next;

    public LinkedList(int value) {
      this.value = value;
      this.next = null;
    }
  }

  public LinkedList nodeSwap(LinkedList head) {
    // Write your code here.
    if(head==null || head.next==null) {
      return head;
    }

    LinkedList next = head.next;
    head.next = nodeSwap(head.next.next);
    next.next = head;

    return next;
  }
}
