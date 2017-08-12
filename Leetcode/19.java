import java.util.*;

public class Solution
{
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode removeNthFromEnd(ListNode head, int n)
    {
        Stack<ListNode> stack = new Stack<>();
        ListNode temp = head, current = null, pre = null;
        if(head == null)
            return null;
        while(temp != null)
        {
            stack.push(temp);
            temp = temp.next;
        }
        if(n == stack.size())
            return head.next;

        for(int i = 1; i <= n; i++)
        {
            current = stack.pop();
            pre = stack.peek();
        }

        pre.next = current.next;

        return head;
    }
}