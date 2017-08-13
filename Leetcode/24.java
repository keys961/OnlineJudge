public class Solution
{
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int x){ val = x; }
    }

    private ListNode nextHead(ListNode node)
    {
        if(node.next == null || node.next.next == null)
            return node.next;
        return node.next.next;
    }

    public ListNode swapPairs(ListNode head)
    {
        if(head == null)
            return null;
        ListNode temp = head, tempNext = head.next;
        ListNode temp2, newHead;
        if(tempNext != null)
            newHead = tempNext;
        else
            newHead = temp;
        while(temp != null && tempNext != null)
        {
            ListNode nextHead = nextHead(tempNext);
            temp2 = tempNext.next;
            temp.next = nextHead;
            tempNext.next = temp;
            temp = temp2;
            tempNext = temp == null ? null : temp.next;
        }
        return newHead;
    }
}