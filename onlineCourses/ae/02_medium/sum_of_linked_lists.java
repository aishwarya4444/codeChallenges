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

  public LinkedList sumOfLinkedLists(LinkedList linkedListOne, LinkedList linkedListTwo) {
    // Write your code here.
    LinkedList head=null, tail=null;
    int sum=0;

    while(linkedListOne!=null || linkedListTwo!=null) {
      if(linkedListOne!=null) {
        sum += linkedListOne.value;
        linkedListOne = linkedListOne.next;
      }
      if(linkedListTwo!=null) {
        sum += linkedListTwo.value;
        linkedListTwo = linkedListTwo.next;
      }
      if(head==null) {
        head = new LinkedList(sum%10);
        tail = head;
        sum /= 10;
      } else {
        tail.next = new LinkedList(sum%10);
        tail = tail.next;
        sum /= 10;
      }
    }

    if(sum!=0) {
      tail.next = new LinkedList(sum);
    }

    return head;
  }
}
