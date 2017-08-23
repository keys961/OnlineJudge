public class Solution
{
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode deleteDuplicates(ListNode head)
    {
        if(head == null)
            return head;
        ListNode pre = new ListNode(Integer.MAX_VALUE);
        pre.next = head;
        ListNode current = head, next = head.next;
        ListNode newHead = pre;
        while(next != null)
        {
            if(next.val != current.val)
            {
                current.next = next;
                current = next;
                next = next.next;
            }
            else
            {
                next = next.next;
                current.next = next;
            }
        }
        return newHead.next;
    }
}