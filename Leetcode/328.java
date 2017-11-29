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
  public ListNode oddEvenList(ListNode head)
    {
        if(head != null)
        {
            ListNode oddNode = head, evenNode = head.next, evenHead = evenNode;

            while (evenNode != null && evenNode.next != null) //node number not the value
            {
                oddNode.next = oddNode.next.next;
                evenNode.next = evenNode.next.next;
                oddNode = oddNode.next;
                evenNode = evenNode.next;
            }

            oddNode.next = evenHead;
        }
        return head;
    }
}