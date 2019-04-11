
class ListNode {
    int val;
    ListNode next;
    public ListNode(int x) {
        this.val = x;
        this.next = null;
    }
}
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode p = l1, q = l2, curr = dummyHead;
        int carry = 0;
        while(p != null || q != null) {
            int x = (p!=null) ? p.val : 0;
            int y = (q!=null) ? q.val : 0;
            int sum = carry + x+ y;
            carry = sum /10;
            curr.next = new ListNode(sum %10);
            curr = curr.next;
            if(p != null) {
                p = p.next;
            }
            if(q != null) {
                q = q.next;
            }
        }
        if(carry > 0) {
            curr.next = new ListNode(carry);
        }
        return dummyHead.next;
    }
    public static void main(String[] args) {
        ListNode a_n1 = new ListNode(2);
        ListNode a_n2 = new ListNode(4);
        ListNode a_n3 = new ListNode(3);
        a_n1.next = a_n2;
        a_n2.next = a_n3;
        a_n3.next = null;

        ListNode b_n1 = new ListNode(5);
        ListNode b_n2 = new ListNode(6);
        ListNode b_n3 = new ListNode(4);
        b_n1.next = b_n2;
        b_n2.next = b_n3;
        b_n3.next = null;

        Solution s = new Solution();
        ListNode result = s.addTwoNumbers(a_n1, b_n1);
        while(result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
        System.out.println();
    }
}