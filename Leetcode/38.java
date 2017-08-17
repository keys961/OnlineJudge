public class Solution
{

    public String countAndSay(int n)
    {
        if(n == 0)
            return "";
        String result = "1";
        while(--n != 0)
        {
            String current = "";
            for(int i = 0; i < result.length(); i++)
            {
                int count = 1;
                while((i + 1 < result.length() && result.charAt(i) == result.charAt(i + 1)))
                {
                    count++;
                    i++;
                }
                current += Integer.toString(count) + result.charAt(i);
            }
            result = current;
        }
        return result;
    }
}