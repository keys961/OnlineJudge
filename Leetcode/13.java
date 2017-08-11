import java.util.*;

public class Solution
{

    public int romanToInt(String s)
    {
        Map<Character, Integer> map = new HashMap<>();
        map.put('M', 1000);
        map.put('D', 500);
        map.put('C', 100);
        map.put('L', 50);
        map.put('X', 10);
        map.put('V', 5);
        map.put('I', 1);

        int res = 0, len = s.length();
        for(int i = 0; i < len - 1; i++)
        {
            if(map.get(s.charAt(i)) < map.get(s.charAt(i + 1)))
                res -= map.get(s.charAt(i));
            else
                res += map.get(s.charAt(i));
        }
        return res + map.get(s.charAt(len - 1));
    }

}