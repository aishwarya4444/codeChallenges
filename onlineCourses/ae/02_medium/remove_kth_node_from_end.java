import java.util.*;

class Program {
  public static void removeKthNodeFromEnd(LinkedList head, int k) {
    // Write your code here.
    LinkedList slow=head, fast=head, tmp;

    for(int i=1; i<k; i++) {
      fast = fast.next;
    }

    while(fast.next != null) {
      slow = slow.next;
      fast = fast.next;
    }

    // head has to be deleted
    if(slow == head) {
      if(head.next == null) {
        head = null;
        return;
      }
      head.value = slow.next.value;
      head.next = slow.next.next;
      return;
    }

    // tail has to be deleted
    if(slow.next == null) {
      while(head.next != slow) {
        head = head.next;
      }
      head.next = null;
      return;
    }

    // some node in middle has to be deleted
    slow.value = slow.next.value;
    slow.next = slow.next.next;
  }

  static class LinkedList {
    int value;
    LinkedList next = null;

    public LinkedList(int value) {
      this.value = value;
    }
  }
}
