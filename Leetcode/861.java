class Solution
{
    public int matrixScore(int[][] A) 
    {
        flipRow(A);
        flipColumn(A);
        return getSum(A);
    }
    
    private int getSum(int[][] A)
    {
        int sum = 0;
        for(int i = 0; i < A.length; i++)
        {
            int base = 1;
            for(int j = A[i].length - 1; j >= 0; j--)
            {
                if(A[i][j] == 1)
                    sum += base;
                base <<= 1;
            }
        }
        
        return sum;
    }
    
    private void flipRow(int[][] A)
    {
        int len = A.length;
        for(int i = 0; i < len; i++)
        {
            int diff = 0;
            int base = 1;
            for(int j = A[i].length - 1; j >= 0; j--)
            {
                if(A[i][j] == 1)
                    diff -= base;
                else
                    diff += base;
                base <<= 1;
            }
            
            if(diff > 0)
                for(int j = 0; j < A[i].length; j++)
                    A[i][j] = A[i][j] == 1 ? 0 : 1;
        }
    }
    
    private void flipColumn(int[][] A)
    {
        int len = A[0].length;
        for(int i = 0; i < A[0].length; i++)
        {
            int zeroCount = 0;
            for(int j = 0; j < A.length; j++)
            {
                if(A[j][i] == 0)
                    zeroCount += 1;
            }
            
            if(zeroCount > A.length / 2)
            {
                for(int j = 0; j < A.length; j++)
                    A[j][i] = A[j][i] == 0 ? 1 : 0;
            }
        }
    }
}