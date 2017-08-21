public class Solution
{
    public String addBinary(String a, String b)
    {
        StringBuilder res = new StringBuilder();
        int indexA = a.length() - 1; //Smaller
        int indexB = b.length() - 1;

        if(indexA > indexB)
            return addBinary(b, a);

        int carry = 0;
        while(indexA >= 0)
        {
            int temp = a.charAt(indexA) + b.charAt(indexB) - 2 * '0' + carry;
            res.insert(0, temp % 2);
            carry = temp / 2;
            indexA--;
            indexB--;
        }
        while(indexB >= 0)
        {
            int temp = b.charAt(indexB) - '0' + carry;
            res.insert(0, temp % 2);
            carry = temp / 2;
            indexB--;
        }
        if(carry != 0)
            res.insert(0, carry);
        return res.toString();
    }
}