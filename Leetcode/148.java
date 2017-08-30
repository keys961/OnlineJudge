// Heap sort: O(nlogn) - O(n)
// Quick sort: O(nlogn) - O(logn)
// Merge sort: O(nlogn) - O(1) --- Linked List, use this way

class Solution 
{
   public ListNode sortList(ListNode head)
    {   //O(nlogn) Merge sort
        if(head == null)
            return null;
        if(head.next == null)
            return head;

        ListNode mid = findMid(head);
        ListNode midNext = mid.next;
        mid.next = null;

        ListNode list1 = sortList(head);
        ListNode list2 = sortList(midNext);

        return merge(list1, list2);
    }

    private ListNode findMid(ListNode head) 
    {
    	//Slow - fast pointer to find mid position
        ListNode slow = head;
        ListNode fast = head;

        while(true)
        {
            if(fast.next == null)
                return slow;
            else if(fast.next.next == null)
                return slow;
            else
            {
                fast = fast.next.next;
                slow = slow.next;
            }
        }
    }

    private ListNode merge(ListNode a, ListNode b)
    {
        ListNode headA = a;
        ListNode headB = b;
        ListNode current = new ListNode(0);
        ListNode head = current;
        while (headA != null && headB != null)
        {
            if(headA.val < headB.val)
            {
                current.next = headA;
                headA = headA.next;
            }
            else
            {
                current.next = headB;
                headB = headB.next;
            }
            current = current.next;
        }

        while (headA != null)
        {
            current.next = headA;
            headA = headA.next;
            current = current.next;
        }

        while (headB != null)
        {
            current.next = headB;
            headB = headB.next;
            current = current.next;
        }

        return head.next;
    }
}