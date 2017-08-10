public class Solution
{
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int val){ this.val = val; }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode head, temp, next;
        head = temp = new ListNode(-1); //Dummy Head Node
        int carry = 0, sum;
        while(l1 != null && l2 != null)
        {
            sum = l1.val + l2.val + carry;
            l1 = l1.next;
            l2 = l2.next;
            next = new ListNode(sum % 10);
            next.next = null;
            carry = sum / 10;
            temp.next = next;
            temp = next;
        }
        while(l1 != null)
        {
            sum = l1.val + carry;
            l1 = l1.next;
            next = new ListNode(sum % 10);
            next.next = null;
            carry = sum / 10;
            temp.next = next;
            temp = temp.next;
        }
        while(l2 != null)
        {
            sum = l2.val + carry;
            l2 = l2.next;
            next = new ListNode(sum % 10);
            next.next = null;
            carry = sum / 10;
            temp.next = next;
            temp = temp.next;
        }
        if(carry == 1)
        {
            next = new ListNode(carry);
            temp.next = next;
            next.next = null;
        }
        return head.next;
    }
}