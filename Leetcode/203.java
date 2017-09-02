class Solution 
{
    public ListNode removeElements(ListNode head, int val) 
    {
        ListNode node = new ListNode(0);
        node.next = head;
        
        ListNode pre = node;
        ListNode current = head;
        
        while(current != null)
        {
            if(current.val == val)
            {
                pre.next = current.next;
                current = current.next;
            }
            else
            {
                pre = current;
                current = current.next;
            }
        }
        return node.next;
    }
}