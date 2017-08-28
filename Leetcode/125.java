class Solution 
{
    public boolean isPalindrome(String s)
    {
        if(s.length() == 0)
            return true;
        s = s.toLowerCase();

        int low = 0, up = s.length() - 1;
        while(low <= up)
        {
            while((s.charAt(low) < 'a' || s.charAt(low) > 'z')
                    && (s.charAt(low) < '0' || s.charAt(low) > '9')
                    && low < s.length() - 1)
                low++;
            while((s.charAt(up) < 'a' || s.charAt(up) > 'z')
                    && (s.charAt(up) < '0' || s.charAt(up) > '9')
                    && up > 0)
                up--;
            if(low > up)
                break;

            if(s.charAt(low) == s.charAt(up))
            {
                low++;
                up--;
            }
            else
                return false;
        }
        return true;
    }
}