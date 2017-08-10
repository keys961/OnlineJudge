public class Solution
{
    public String convert(String s, int numRows)
    {
        if(numRows == 1)
            return s;
        StringBuilder stringBuilder = new StringBuilder();
        int len = s.length();
        for(int i = 1; i <= numRows; i++)
        {
            if(i == 1 || i == numRows)
            {
                int j = i - 1;
                while(j < len)
                {
                    stringBuilder.append(s.charAt(j));
                    j += 2 * numRows - 2;
                }
            }
            else
            {
                int j = i - 1;
                int k = 2 * numRows - 1 - i;
                while(k < len && j < len)
                {
                    stringBuilder.append(s.charAt(j));
                    stringBuilder.append(s.charAt(k));
                    j += 2 * numRows - 2;
                    k += 2 * numRows - 2;
                }
                if(j < len)
                    stringBuilder.append(s.charAt(j));
            }
        }
        return stringBuilder.toString();
    }
}