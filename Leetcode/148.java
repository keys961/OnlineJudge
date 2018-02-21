// Heap sort: O(nlogn) - O(n)
// Quick sort: O(nlogn) - O(logn)
// Merge sort: O(nlogn) - O(1)/O(logn) --- Linked List, use this way

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution 
{
    public ListNode sortList(ListNode head)
    {
        if(head == null)
            return null;
        if(head.next == null)
            return head;
        
        ListNode mid = findMidNode(head);
        ListNode head1 = head, head2 = mid.next;
        mid.next = null;//split 
        
        head1 = sortList(head1);
        head2 = sortList(head2);
        
        return merge(head1, head2);
        
    }
    
    private ListNode merge(ListNode h1, ListNode h2)
    {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        while(h1 != null && h2 != null)
        {
            if(h1.val < h2.val)
            {
                current.next = h1;
                h1 = h1.next;
            }
            else
            {
                current.next = h2;
                h2 = h2.next;
            }
            current = current.next;
        }
        
        if(h1 != null)
            current.next = h1;
        else
            current.next = h2;
        
        return dummy.next;
    }
    
    private ListNode findMidNode(ListNode node)
    {
        ListNode slow = node, fast = node;
        for(;;)
        {
            if(slow.next == null)
                return slow;
            if(fast.next == null || fast.next.next == null)
                return slow;
            slow = slow.next;
            fast = fast.next.next;
        }
       // return slow;
    }
}