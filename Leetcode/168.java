public class Solution
{
    public String convertToTitle(int n)
    {
        StringBuilder stringBuilder = new StringBuilder();
        while (n > 0)
        {
            n--;
            stringBuilder.insert(0, (char)('A' + n % 26));
            n /= 26;
        }
        return stringBuilder.toString();
    }
}