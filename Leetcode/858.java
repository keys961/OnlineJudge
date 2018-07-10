class Solution
{
    public int mirrorReflection(int p, int q) 
    {
        if(q == 0)
            return 0;
        
        int m = findLCM(p, q);
        
        if(m / q % 2 == 0)
            return 2;
        if(m / p % 2 == 0)
            return 0;
        return 1;
    }
    
    private int findLCM(int p, int q)
    {
        return p * q / findGCD(p, q);
    }
    
    private int findGCD(int p, int q)
    {
        if(q != 0)
            return findGCD(q, p % q);
        return p;
    }
}