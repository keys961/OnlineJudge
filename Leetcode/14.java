public class Solution
{
    public String longestCommonPrefix(String[] strs) 
    {
        StringBuilder stringBuilder = new StringBuilder();
        if(strs.length == 0)
            return stringBuilder.toString();
        int minLen = Integer.MAX_VALUE;
        for(String s : strs)
            if(s.length() < minLen)
                minLen = s.length();
        int i = 0;
        while(i < minLen)
        {
            char c = strs[0].charAt(i);
            for(int j = 1; j < strs.length; j++)
                if(strs[j].charAt(i) != c)
                    return stringBuilder.toString();
            stringBuilder.append(c);
            i++;
        }
        return stringBuilder.toString();
    }
}