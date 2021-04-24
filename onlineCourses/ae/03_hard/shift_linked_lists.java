import java.util.*;

class Program {
  public static LinkedList shiftLinkedList(LinkedList head, int k) {
    // Write your code here.
    LinkedList h1=head, h2=head;
    int n, N=0;

    while(h1 != null) {
      h1 = h1.next;
      N++;
    }

    while(k < 0) {
      k += N;
    }
    k %= N;

    h1 = head;
    for(n=1; n<=k; n++) {
      h2 = h2.next;
    }

    while(h2.next != null) {
      h1 = h1.next;
      h2 = h2.next;
    }
    h2.next = head;
    head = h1.next;
    h1.next = null;

    return head;
  }

  static class LinkedList {
    public int value;
    public LinkedList next;

    public LinkedList(int value) {
      this.value = value;
      next = null;
    }
  }
}
