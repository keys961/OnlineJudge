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
    public boolean isPalindrome(ListNode head)
    {
        if(head == null || head.next == null)
            return true;
        
        ListNode slow = head, fast = head;
        while(fast != null)
        {
            if(fast.next == null || fast.next.next == null)
                break;
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode head2 = reverseList(slow.next);//to satisfy space O(1), reverse the latter part of linked list.
        ListNode head1 = head;
        
        while(head2 != null)
        {
            if(head1.val != head2.val)
                return false;
            head1 = head1.next;
            head2 = head2.next;
        }
        
        return true;   
    }
    
    private ListNode reverseList(ListNode head)
    {
        if(head == null || head.next == null)
            return head;
        
        ListNode pre = null, cur = head, next = head.next;
        while(cur != null)
        {
            cur.next = pre;
            pre = cur;
            cur = next;
            if(next != null)
                next = next.next;
        }
        
        return pre;
    }
}