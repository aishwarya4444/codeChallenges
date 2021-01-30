
class ListNode {
    int value = 0;
    ListNode next;

    ListNode(int value) {
        this.value = value;
    }
}

class RearrangeList {
    public static ListNode reverse(ListNode head) {
        ListNode prev=null, curr=head, next=null;

        if(head==null || head.next==null) {
            return head;
        }

        while(curr!=null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public static void reorder(ListNode head) {
        ListNode slow=head, fast=head, h1, h2, tmp;

        if(head==null || head.next==null) {
            return;
        }

        while(fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow = reverse(slow);
        h1 = head;
        h2 = slow;

        while(h1!=null && h2!=null) {
            tmp = h1.next;
            h1.next = h2;
            h1 = tmp;

            tmp = h2.next;
            h2.next = h1;
            h2 = tmp;
        }

        if(h1!=null) {
            h1.next = null;
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(2);
        head.next = new ListNode(4);
        head.next.next = new ListNode(6);
        head.next.next.next = new ListNode(8);
        head.next.next.next.next = new ListNode(10);
        head.next.next.next.next.next = new ListNode(12);
        RearrangeList.reorder(head);
        while (head != null) {
            System.out.print(head.value + " ");
            head = head.next;
        }
    }
}

/*
https://leetcode.com/problems/reorder-list/
class Solution {
    public ListNode reverse(ListNode head) {
        ListNode prev=null, curr=head, next=null;

        if(head==null || head.next==null) {
            return head;
        }

        while(curr!=null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    public void reorderList(ListNode head) {
        ListNode slow=head, fast=head, h1, h2, tmp;

        if(head==null || head.next==null) {
            return;
        }

        while(fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow = reverse(slow);
        h1 = head;
        h2 = slow;

        while(h1!=null && h2!=null) {
            tmp = h1.next;
            h1.next = h2;
            h1 = tmp;

            tmp = h2.next;
            h2.next = h1;
            h2 = tmp;
        }

        if(h1!=null) {
            h1.next = null;
        }
    }
}
*/