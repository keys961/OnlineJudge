public class Solution
{

    public String multiply(String num1, String num2)
    {
        int[] digits = new int[num1.length() + num2.length()];
        StringBuilder n1 = new StringBuilder(num1);
        StringBuilder n2 = new StringBuilder(num2);
        n1 = n1.reverse();
        n2 = n2.reverse();

        for(int i = 0; i < n1.length(); i++)
            for(int j = 0; j < n2.length(); j++)
                digits[i + j] += (n1.charAt(i) - '0') * (n2.charAt(j) - '0');
        int carry = 0, digit = 0;
        for(int i = 0; i < n1.length() + n2.length(); i++)
        {
            digit = digits[i] + carry;
            digits[i] = digit % 10;
            carry = digit / 10;
        }
        int i = n1.length() + n2.length() - 1;
        for(; i >= 0; i--)
            if(digits[i] != 0)
                break;
        String res = "";
        while(i >= 0)
        {
            res = res + (digits[i]);
            i--;
        }
        if(res.equals(""))
            return "0";
        return res;
    }
}