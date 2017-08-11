import java.util.*;

public class Solution
{
    private String[] characters = new String[]{"", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"};
            
    List<String> res = new ArrayList<>();

    private void getString(String digits, String letter)
    {
        if(letter.length() == digits.length())
        {
            res.add(letter);
            return;
        }
        char temp = digits.charAt(letter.length());
        for(int i = 0; i < characters[temp - '0'].length(); i++)
            getString(digits, letter + characters[temp - '0'].charAt(i));
    }

    public List<String> letterCombinations(String digits)
    {
        if(digits.length() == 0)
            return res;
        getString(digits, "");
        return res;
    }
}