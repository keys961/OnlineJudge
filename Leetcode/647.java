class Solution 
{
    public int countSubstrings(String s)
    {
        int index;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int ptr1, ptr2;
            index = i;
            //count single
            ptr1 = ptr2 = index;
            while(ptr1 >= 0 && ptr2 < s.length())
            {
                if(s.charAt(ptr1) == s.charAt(ptr2))
                {
                    cnt++;
                    ptr1--;
                    ptr2++;
                }
                else
                    break;
            }
            //count double
            ptr1 = index; ptr2 = index + 1;
            while(ptr1 >= 0 && ptr2 < s.length())
            {
                if(s.charAt(ptr1) == s.charAt(ptr2))
                {
                    cnt++;
                    ptr1--;
                    ptr2++;
                }
                else
                    break;
            }
        }
        return cnt;
    }
}