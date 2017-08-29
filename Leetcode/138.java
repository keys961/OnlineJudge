import java.util.*;

public class Solution
{
    public RandomListNode copyRandomList(RandomListNode head)
    {
        RandomListNode temp = head;
        RandomListNode newHead = new RandomListNode(0);
        RandomListNode current = newHead;
        HashMap<RandomListNode, Integer> map = new HashMap<>();
        HashMap<RandomListNode, RandomListNode> randomPtrMap =
                new HashMap<>();
        map.put(null, -1);
        int i = 0;
        while(temp != null)
        {
            map.put(temp, i++);
            randomPtrMap.put(temp, temp.random);
            current.next = new RandomListNode(temp.label);
            current = current.next;
            temp = temp.next;
        }
        current = newHead.next;
        temp = head;
        while(current != null)
        {
            RandomListNode random = newHead.next;
            int index = map.get(randomPtrMap.get(temp));
            if(index == -1)
                current.random = null;
            else
            {
                while (index > 0)
                {
                    random = random.next;
                    index--;
                }
                current.random = random;
            }
            current = current.next;
            temp = temp.next;
        }
        return newHead.next;
    }
}