class Solution 
{
    public boolean buddyStrings(String A, String B) 
    {
        if(A.length() != B.length())
            return false;
        
        int[] mapA = new int[26];
        int[] mapB = new int[26];
        int len = A.length();
        int diff = 0;
        boolean flag = false;
        
        for(int i = 0; i < len; i++)
        {
            char a = A.charAt(i);
            char b = B.charAt(i);
            
            mapA[a - 'a']++;
            mapB[b - 'a']++;
            if(a != b)
                diff++;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(mapA[i] != mapB[i])
                return false;
            if(mapA[i] >= 2)
                flag = true;
        }
        if(diff == 2 || diff == 0 && flag)
            return true;
        return false;
    }
}