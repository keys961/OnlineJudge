import java.util.*;

class Solution 
{
    public boolean isPalindrome(ListNode head)
    {
        if(head == null)
            return true;
        List<Integer> list = new ArrayList<>();
        while(head != null)
        {
            list.add(head.val);
            head = head.next;
        }
        
        int low = 0, up = list.size() - 1;
        while(low <= up)
        {
            if(!list.get(low).equals(list.get(up)))
                return false;
            low++;
            up--;
        }
        return true;
    }
}