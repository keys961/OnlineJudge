public class Solution
{

    public class ListNode
    {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode reverseBetween(ListNode head, int m, int n)
    {
        if(n - m < 1 || head == null || head.next == null)
            return head;
        n -= m;
        ListNode pre = new ListNode(Integer.MAX_VALUE);//Dummy
        ListNode newHead = pre;
        pre.next = head;

        ListNode start = head, tail = head, post = tail.next;

        while(m > 1)
        {
            pre = start;
            start = start.next;
            m--;
        }
        tail = start.next;
        post = tail.next;
        while(n > 1)
        {
            tail = tail.next;
            post = post.next;
            n--;
        }

        ListNode preNode = start, currentNode = start.next, nextNode = currentNode.next;
        while(preNode != tail)
        {
            currentNode.next = preNode;
            preNode = currentNode;
            currentNode = nextNode;
            if(nextNode != null)
                nextNode = nextNode.next;
        }
        pre.next = tail;
        start.next = post;
        return newHead.next;
    }
}