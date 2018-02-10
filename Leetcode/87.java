class Solution 
{
    public boolean isScramble(String s1, String s2)
    {
        if(s1 == null && s2 == null)
            return true;

        if(s1.length() == 0 && s2.length() == 0)
            return true;

        if(s1.length() == 1 && s2.length() == 1)
            return s1.charAt(0) == s2.charAt(0);

        if(!checkEquals(s1, s2))
            return false;

        for(int len = 1; len <= s1.length() - 1; len++)
        {
           if(isScramble(s1.substring(0, len), s2.substring(0, len))
                   && isScramble(s1.substring(len), s2.substring(len)))
               return true;
           if(isScramble(s1.substring(0, len), s2.substring(s1.length() - len))
                   && isScramble(s1.substring(len), s2.substring(0, s1.length() - len)))
               return true;
        }

        return false;
    }

    private boolean checkEquals(String s1, String s2)
    {
        if(s1.length() != s2.length())
            return false;
        int[] count = new int[256];
        for(int i = 0; i < s1.length(); i++)
        {
            count[s2.charAt(i)]--;
            count[s1.charAt(i)]++;
        }
        for(int c : count)
            if(c != 0)
                return false;
        return true;
    }
}