public class Solution 
{
    public String reverseWords(String s)
    {
        s = s.trim();
        if(s.length() == 0)
            return "";
        String[] tokens = s.split("[\\s]+");
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(tokens[tokens.length - 1]);
        for(int i = tokens.length - 2; i >= 0; i--)
            stringBuilder.append(" " + tokens[i]);
        return stringBuilder.toString();
    }
}