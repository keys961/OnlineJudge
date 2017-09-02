import java.util.*;

public class Solution
{
    public boolean isIsomorphic(String s, String t)
    {
        if(s.length() != t.length())
            return false;
        Map<Character, Character> map = new HashMap<>();

        for(int i = 0; i < s.length(); i++)
        {
            if(!map.containsKey(s.charAt(i)))
            {
                if(map.containsValue(t.charAt(i))) //Exception 01
                    return false;
                map.put(s.charAt(i), t.charAt(i));

            }
            else
            {
                if(map.get(s.charAt(i)) != t.charAt(i)) //Exception 02
                    return false;
            }
        }
        return true;
    }
}