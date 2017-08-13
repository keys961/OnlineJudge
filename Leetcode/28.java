public class Solution
{
    public int strStr(String haystack, String needle)
    {
        //return haystack.indexOf(needle);
        if(haystack.length() == 0 || needle.length() == 0)
            return -1;
        for(int i = 0; ; i++)
        {
            for(int j = 0; ; j++)
            {
                if(needle.charAt(j) == '\0')
                    return i;
                if(haystack.charAt(i + j) == '\0')
                    return -1;
                if(haystack.charAt(i + j) != needle.charAt(j))
                    break;
            }
        }
    }
}