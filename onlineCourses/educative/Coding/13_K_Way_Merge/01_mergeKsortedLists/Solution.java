/*
https://leetcode.com/problems/merge-k-sorted-lists/
 */

import java.util.*;

class ListNode {
    int value;
    ListNode next;

    ListNode(int value) {
        this.value = value;
    }
}

class MergeKSortedLists {

    public static ListNode merge(ListNode[] lists) {
        ListNode result = null, tmp = null;
        PriorityQueue<ListNode> minHeap = new PriorityQueue<ListNode>((node1, node2) -> node1.value - node2.value);

        for(ListNode node: lists) {
            if(node!=null) {
                minHeap.add(node);
            }
        }

        while(minHeap.size() > 0) {
            ListNode node = minHeap.poll();
            if(tmp==null) {
                tmp = node;
                result = node;
            } else {
                tmp.next = node;
                tmp = node;
            }
            if(node.next != null) {
                minHeap.add(node.next);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(2);
        l1.next = new ListNode(6);
        l1.next.next = new ListNode(8);

        ListNode l2 = new ListNode(3);
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(7);

        ListNode l3 = new ListNode(1);
        l3.next = new ListNode(3);
        l3.next.next = new ListNode(4);

        ListNode result = MergeKSortedLists.merge(new ListNode[] { l1, l2, l3 });
        System.out.print("Here are the elements form the merged list: ");
        while (result != null) {
            System.out.print(result.value + " ");
            result = result.next;
        }
    }
}
