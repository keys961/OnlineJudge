import java.util.*;

public class Solution
{
    private List<List<String>> lists = new ArrayList<>();

    private boolean isPalindrome(String s)
    {
        int i = 0, j = s.length() - 1;
        while(i <= j)
        {
            if(s.charAt(i++) != s.charAt(j--))
                return false;
        }
        return true;
    }

    private void helper(String s, List<String> list)
    {
        if(s.equals("") || s == null)
        {
            lists.add(list);
            return;
        }

        for(int i = 0; i < s.length(); i++)
        {
            String temp = s.substring(0, i + 1);
            if(isPalindrome(temp))
            {
                List<String> newList = new ArrayList<>(list);
                newList.add(temp);
                helper(s.substring(i + 1), newList);
            }
        }
    }

    public List<List<String>> partition(String s)
    {
        helper(s, new ArrayList<>());
        return lists;
    }
}