class Solution
{
    public boolean isSubsequence(String s, String t)
    {
        if(t.length() < s.length())
            return false;
        int ptrS = 0, ptrT = 0;
        while(ptrS < s.length() && ptrT < t.length())
        {
            if(s.charAt(ptrS) == t.charAt(ptrT))
                ptrS++;
            ptrT++;
        }
        return ptrS == s.length();
    }
}