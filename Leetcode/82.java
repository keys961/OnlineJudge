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
        boolean flag = false;
        while(next != null)
        {
            if(next.val != current.val)
            {
                if(flag)
                {
                    pre.next = next;
                    flag = false;
                }
                else
                    pre = current;

                current = next;
                next = next.next;
            }
            else
            {
                flag = true;
                next = next.next;
            }
        }
        if(flag)
            pre.next = null;
        return newHead.next;
    }
}