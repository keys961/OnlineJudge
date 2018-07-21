class Solution 
{
    public int binaryGap(int N) 
    {
        int num = N;
        int maxLen = 0;
        int len = -1;
        while(num > 0)
        {
            if(num % 2 != 0)
            {
                if(len == -1)
                    len = 0;
                if(len > maxLen)
                    maxLen = len;
                len = 1;
            }
            else 
            {
                if(len != -1)
                    len++;
            }
            num /= 2;
        }
        
        return maxLen;
    }
}