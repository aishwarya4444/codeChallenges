import java.util.*;

class Program {
  public static LinkedList rearrangeLinkedList(LinkedList head, int k) {
    // Write your code here.
    LinkedList sh = null, st = null; // small
    LinkedList eh = null, et = null; // equal
    LinkedList bh = null, bt = null; // big

    LinkedList node = head;

    while(node != null) {
      if(node.value < k) {
        LinkedListPair small = growLinkedList(sh, st, node);
        sh = small.head;
        st = small.tail;
      } else if(node.value > k) {
        LinkedListPair big = growLinkedList(bh, bt, node);
        bh = big.head;
        bt = big.tail;
      } else {
        LinkedListPair equal = growLinkedList(eh, et, node);
        eh = equal.head;
        et = equal.tail;
      }

      LinkedList prev = node;
      node = node.next;
      prev.next = null;
    }

    LinkedListPair firstPair = connectLinkedLists(sh, st, eh, et);
    LinkedListPair finalPair = connectLinkedLists(firstPair.head, firstPair.tail, bh, bt);

    return finalPair.head;
  }

  public static LinkedListPair growLinkedList(LinkedList h, LinkedList t, LinkedList node) {
    LinkedList head = h;
    LinkedList tail = node;

    if(head == null) {
      head = node;
    }
    if(t != null) {
      t.next = node;
    }

    return new LinkedListPair(head, tail);
  }

  public static LinkedListPair connectLinkedLists(LinkedList h1, LinkedList t1, LinkedList h2, LinkedList t2) {
    LinkedList head = h1!=null ? h1 : h2;
    LinkedList tail = t2!=null ? t2 : t1;

    if(t1 != null) {
      t1.next = h2;
    }

    return new LinkedListPair(head, tail);
  }

  static class LinkedListPair {
    public LinkedList head;
    public LinkedList tail;

    public LinkedListPair(LinkedList head, LinkedList tail) {
      this.head = head;
      this.tail = tail;
    }
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
