import java.util.*;

public class Solution
{
    public List<String> findRepeatedDnaSequences(String s)
    {
        List<String> list = new ArrayList<>();
        if(s.length() <= 10)
            return list;
        HashMap<String, Integer> map = new HashMap<>();
        for(int i = 10; i <= s.length(); i++)
        {
            String part = s.substring(i - 10, i);
            if(!map.containsKey(part))
                map.put(part, 1);
            else if(map.containsKey(part) && map.get(part) == 1)
            {
                list.add(part);
                map.put(part, 2);
            }
        }
        return list;
    }
}