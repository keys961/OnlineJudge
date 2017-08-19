import java.util.*;

public class Solution
{
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int val){ this.val = val; }
    }

    public ListNode rotateRight(ListNode head, int k)
    {
        if(k == 0 || head == null)
            return head;

        Stack<ListNode> stack = new Stack<>();
        ListNode temp = head, tail;
        while(temp != null)
        {
            stack.push(temp);
            temp = temp.next;
        }
        k = k % stack.size();
        if(k == 0)
            return head;
        tail = stack.pop();

        for(int i = 0; i < k; i++)
            temp = stack.pop();

        tail.next = head;
        head = temp.next;
        temp.next = null;

        return head;
    }
}