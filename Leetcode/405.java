class Solution
{
    private char[] digit = new char[]{'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    public String toHex(int num)
    {
        if(num == 0)
            return "0";
        StringBuilder res = new StringBuilder();
        for(int i = 0; i < 8 && num != 0; i++)
        {
            res.insert(0, digit[num & 15]);
            num >>= 4;
        }
        
        return res.toString();
    }
}