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
    private PriorityQueue<ListNode> minHeap = new PriorityQueue<>(
        (o1, o2) -> (o1.val - o2.val)
    );
    
    public ListNode mergeKLists(ListNode[] lists) 
    {
        ListNode head = new ListNode(0);
        ListNode current = head;
        
        for(ListNode node : lists)
        {
            if(node != null)
                minHeap.add(node);
        }
        
        while(!minHeap.isEmpty())
        {
            ListNode temp = minHeap.poll();
            if(temp.next != null)
                minHeap.add(temp.next);
            
            current.next = temp;
            current = current.next;
        }
        
        return head.next;
    }
}