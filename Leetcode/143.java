import java.util.*;

public class Solution
{
    public void reorderList(ListNode head)
    {
        if(head == null)
            return;
        List<ListNode> list = new ArrayList<>();
        ListNode temp = head;
        while(temp != null)
        {
            list.add(temp);
            temp = temp.next;
        }

        int i = 0;
        ListNode start = list.get(0),
                end = list.get(list.size() - 1);
        while(start != end && start.next != end)
        {
            end.next = start.next;
            start.next = end;
            i++;
            end = list.get(list.size() - 1 - i);
            start = list.get(i);
        }

        if(start == end)
            start.next = null;
        if(start.next == end)
            end.next = null;
    }
}