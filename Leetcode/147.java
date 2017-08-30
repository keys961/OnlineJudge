import java.util.*;

public class Solution
{
    public ListNode insertionSortList(ListNode head)
    {
        if(head == null)
            return null;

        List<ListNode> list = new ArrayList<>();
        ListNode temp = head;
        while(temp != null)
        {
            list.add(temp);
            temp = temp.next;
        }
        int j;
        for(int i = 1; i < list.size(); i++)
        {
            ListNode pivot = list.get(i);
            for(j = i; j > 0; j--)
            {
                if(list.get(j - 1).val > pivot.val)
                    list.set(j, list.get(j - 1));
                else
                    break;
            }
            list.set(j, pivot);
        }
        for(int i = 0; i < list.size() - 1; i++)
            list.get(i).next = list.get(i + 1);
        list.get(list.size() - 1).next = null;
        return list.get(0);
    }
}