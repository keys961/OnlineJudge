class Solution
{
    public int primePalindrome(int N)
    {
        // Even digit palindrome % 11 == 0
        // So we just consider the odd one..
        // for any palindrome with even digits:
        // abcdeedcba % 11
        // = (a * 10000001 + b * 100001 * 10 + c * 1001 * 100 + d * 11 * 1000) % 11
        // = 0
        // 
        // Other way:
        // Implement nextPalindrome to speed up iteration using array...
        if(N >= 8 && N <= 11) 
            return 11;
        for(int x = 1; x < 100000; x++) 
        {
            String s = Integer.toString(x); // left side & middle pivot
            String r = new StringBuilder(s).reverse().toString().substring(1); // right side
            int y = Integer.parseInt(s + r);
            if (y >= N && isPrime(y)) 
                return y;
        }
        return -1;
    }
    
    private boolean isPrime(int n)
    {
        if(n == 1)
            return false;
        if(n == 2 || n == 3)
            return true;
        int limit = (int)Math.sqrt(n) + 1;
        for(int i = 2; i <= limit; i++)
            if(n % i == 0)
                return false;
        return true;
    }
}