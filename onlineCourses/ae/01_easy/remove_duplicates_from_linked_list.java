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

  public LinkedList removeDuplicatesFromLinkedList(LinkedList linkedList) {
    // Write your code here.
    LinkedList curr = linkedList, head;
    while(curr!=null) {
      head = curr.next;
      while(head!=null && curr.value==head.value) {
        head = head.next;
      }
      curr.next = head;
      curr = curr.next;
    }
    return linkedList;
  }
}
