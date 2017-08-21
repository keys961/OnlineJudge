public class Solution
{
    public int[] plusOne(int[] digits)
    {
        int carry = 0;
        for(int i = digits.length - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            if(i == digits.length - 1)
                sum += 1;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        int[] res;
        if(carry != 0)
        {
            res = new int[digits.length + 1];
            res[0] = carry;
            for(int i = 1; i <= digits.length; i++)
                res[i] = digits[i - 1];
        }
        else
        {
            res = new int[digits.length];
            for(int i = 0; i < digits.length; i++)
                res[i] = digits[i];
        }

        return res;
    }
}