/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null;
        head = new ListNode(0);
        ListNode ln = head;
        int temp = 0;
        int temp2 = 0;
        int l1val = 0;
        int l2val = 0;
        while(l1 != null || l2 != null) {
            l1val = l1==null?0:l1.val;
            l2val = l2==null?0:l2.val;
            temp2 = l1val + l2val + temp;
            temp = temp2/10;
            temp2 %= 10;
            ln.next = new ListNode(temp2);
            ln = ln.next;
            l1 = l1==null?null:l1.next;
            l2 = l2==null?null:l2.next;

        }
        if (temp == 1) {
            ln.next = new ListNode(temp);
        }
        return head.next;
    }
}