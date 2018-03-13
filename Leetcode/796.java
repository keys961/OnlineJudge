class Solution
{
    private String rotate(String s, int n)
    {
        int len = s.length();
        
        n = n % len;
        if(n == 0)
            return s;
        
        return s.substring(n, len) + s.substring(0, n);
    }
    
    public boolean rotateString(String A, String B) 
    {
        if(A == null && B == null)
            return true;
        
        if(A == null || B == null)
            return false;
        
        if(A.length() != B.length())
            return false;
        
        int len = A.length();
        for(int i = 0; i < len; i++)
        {
            if(A.equals(rotate(B, i)))
                return true;
        }
        return false;
    }
}