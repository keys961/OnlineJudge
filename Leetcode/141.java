public class Solution 
{
    public boolean hasCycle(ListNode head)
    {
        ListNode slow = head, fast = head;
        while(fast != null)
        {
            slow = slow.next;
            if(slow == null)
                return false;
            fast = fast.next;
            if(fast == null)
                return false;
            fast = fast.next;
            if(fast == null)
                return false;
            
            if(slow == fast)
                return true;
        }
        return false;
    }
}