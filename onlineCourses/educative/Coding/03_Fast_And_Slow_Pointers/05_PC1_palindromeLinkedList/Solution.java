class ListNode {
    int value = 0;
    ListNode next;

    ListNode(int value) {
        this.value = value;
    }
}

class PalindromicLinkedList {

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

    public static boolean isPalindrome(ListNode head) {
        // TODO: Write your code here
        ListNode slow=head, fast=head, tail;
        boolean result = true;

        if(head==null || head.next==null) {
            return result;
        }

        while(fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow = reverse(slow);
        tail = slow;

        while(head!=slow && tail!=null) {
            if(head.value!=tail.value) {
                result = false;
                break;
            }
            head = head.next;
            tail = tail.next;
        }

        reverse(slow);
        return result;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(2);
        head.next = new ListNode(4);
        head.next.next = new ListNode(6);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(2);
        System.out.println("Is palindrome: " + PalindromicLinkedList.isPalindrome(head));

        head.next.next.next.next.next = new ListNode(2);
        System.out.println("Is palindrome: " + PalindromicLinkedList.isPalindrome(head));
    }
}

/*
https://leetcode.com/problems/palindrome-linked-list/
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
    public boolean isPalindrome(ListNode head) {
        ListNode slow=head, fast=head, tail;
        boolean result = true;

        while(fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow = reverse(slow);
        tail = slow;

        while(head!=null && tail!=null) {
            if(head.val!=tail.val) {
                result = false;
                break;
            }
            head = head.next;
            tail = tail.next;
        }

        reverse(slow);
        return result;
    }
}
*/