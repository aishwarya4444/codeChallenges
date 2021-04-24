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

  public LinkedList zipLinkedList(LinkedList linkedList) {
    // Write your code here.
    LinkedList slow = linkedList, fast = linkedList, tail = linkedList, tmp;

    while(fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    fast = reverse(slow);

    while(tail != null && fast != null) {
      tmp = tail.next;
      tail.next = fast;
      tail = tmp;

      tmp = fast.next;
      fast.next = tail;
      fast = tmp;
    }

    if(tail != null) {
      tail.next = null;
    }

    return linkedList;
  }

  private LinkedList reverse(LinkedList head) {
    if(head == null || head.next == null) {
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
