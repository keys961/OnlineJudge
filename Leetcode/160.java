import java.util.*;

public class Solution
{
    private int getLength(ListNode node)
    {
        int len = 0;
        while(node != null)
        {
            len++;
            node = node.next;
        }
        return len;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB)
    {
//        Set<ListNode> set = new HashSet<>();
//        while(headA != null)
//        {
//            set.add(headA);
//            headA = headA.next;
//        }
//        while(headB != null)
//        {
//            if(set.contains(headB))
//                return headB;
//            headB = headB.next;
//        }
//        return null;
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        while (lenA > lenB)
        {
            lenA--;
            headA = headA.next;
        }
        while (lenB > lenA)
        {
            lenB--;
            headB = headB.next;
        }
        
        while(headA != null && headB != null)
        {
            if(headA == headB)
                return headA;
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }
}