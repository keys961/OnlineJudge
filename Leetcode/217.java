import java.util.*;

public class Solution
{
    public boolean containsDuplicate(int[] nums)
    {
        Set<Integer> set = new HashSet<>();
        for(Integer n : nums)
        {
            if(set.contains(n))
                return true;
            set.add(n);
        }
        return false;
    }
}