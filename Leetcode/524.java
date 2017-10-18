class Solution 
{
    private boolean judge(String s, String d)
    {
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < s.length() && ptr2 < d.length())
        {
            if(s.charAt(ptr1) == d.charAt(ptr2))
                ptr2++;
            ptr1++;
        }

        return ptr2 == d.length();
    }

    public String findLongestWord(String s, List<String> d)
    {
        Collections.sort(d, (o1, o2) -> {
            if(o1.length() == o2.length())
                return o1.compareTo(o2);
            return o2.length() - o1.length();
        });

        for(String d0 : d)
            if(judge(s, d0))
                return d0;

        return "";
    }
}