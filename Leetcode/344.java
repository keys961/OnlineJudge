class Solution
{
    public String reverseString(String s) 
    {
        StringBuilder stringBuilder = new StringBuilder(s);
        
        int ptr1 = 0, ptr2 = stringBuilder.length() - 1;
        while(ptr1 < ptr2)
        {
            char temp = stringBuilder.charAt(ptr1);
            stringBuilder.setCharAt(ptr1, stringBuilder.charAt(ptr2));
            stringBuilder.setCharAt(ptr2, temp);
            ptr1++;
            ptr2--;
        }
        
        return stringBuilder.toString();
    }
}