import java.util.*;

public class Solution
{
    public int lengthOfLongestSubstring(String s)
    {
        int len = 0;
        Set<Character> set = new TreeSet<>();
        int head = 0, tail = -1, end = s.length();
        while(head < end)
        {
            if(++tail != end && !set.contains(s.charAt(tail)))
                set.add(s.charAt(tail));
            else
            {
                if(tail - head > len)
                    len = tail - head;
                head++;
                tail = head - 1;
                set.clear();
            }
        }
        return len;
    }
}