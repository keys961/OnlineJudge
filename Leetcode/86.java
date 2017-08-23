public class Solution
{
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode partition(ListNode head, int x)
    {
        // Manage 2 linked list
        ListNode smallHead = new ListNode(0), smallTemp = smallHead;
        ListNode bigHead = new ListNode(0), bigTemp = bigHead;
        while(head != null)
        {
            if(head.val < x)
            {
                smallTemp.next = new ListNode(head.val);
                smallTemp = smallTemp.next;
            }
            else
            {
                bigTemp.next = new ListNode(head.val);
                bigTemp = bigTemp.next;
            }
            head = head.next;
        }
        smallTemp.next = bigHead.next;
        return smallHead.next;
    }
}