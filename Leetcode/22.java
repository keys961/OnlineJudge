import java.util.*;

public class Solution
{
    private List<String> res = new ArrayList<>();

    private void getValidParenthesis(String s, int left, int right, int n)
    {
        if(left == right && right == n)
        {
            res.add(s);
            return;
        }

        if(left < n)
            getValidParenthesis(s + '(', left + 1, right, n);
        if(right < n && right < left)
            getValidParenthesis(s + ')', left, right + 1, n);
    }

    public List<String> generateParenthesis(int n)
    {
        getValidParenthesis("", 0, 0, n);
        return res;
    }
}