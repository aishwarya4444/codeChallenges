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

  public boolean linkedListPalindrome(LinkedList head) {
    // Write your code here.
    if(head == null || head.next == null) {
      return true;
    }
    LinkedList slow = head, fast = head;
    boolean match = true;

    while(fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    fast = reverse(slow);
    while(head != null && fast != null) {
      if(head.value != fast.value) {
        match = false;
        break;
      }
      head = head.next;
      fast = fast.next;
    }
    reverse(slow);

    return match;
  }

  private LinkedList reverse(LinkedList head) {
    if(head == null || head.next==null) {
      return head;
    }

    LinkedList prev = null, curr = head, next = null;
    while(curr != null) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    head = prev;

    return head;
  }
}
