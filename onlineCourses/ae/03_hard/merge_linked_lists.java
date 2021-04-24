import java.util.*;

class Program {
  // This is an input class. Do not edit.
  public static class LinkedList {
    int value;
    LinkedList next;

    LinkedList(int value) {
      this.value = value;
      this.next = null;
    }
  }

  public static LinkedList mergeLinkedLists(LinkedList headOne, LinkedList headTwo) {
    // Write your code here.

    LinkedList head = null, tail = null, minNode = null;

    while(headOne!=null && headTwo!=null) {
      if(headOne.value < headTwo.value) {
        minNode = headOne;
        headOne = headOne.next;
      } else {
        minNode = headTwo;
        headTwo = headTwo.next;
      }

      if(head==null) {
        head = minNode;
        tail = head;
      } else {
        tail.next = minNode;
        tail = tail.next;
      }
    }

    tail.next = headOne!=null ? headOne : headTwo;

    return head;
  }
}
