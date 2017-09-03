public class Solution
{
    public ListNode reverseList(ListNode head)
    {
        if(head == null)
            return head;
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode pre = dummyHead, current = head, next = current.next;

        while(current != null)
        {
            current.next = pre;
            pre = current;
            current = next;
            if(next != null)
                next = next.next;
        }
        dummyHead.next.next = null;
        return pre;
    }
}