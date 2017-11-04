class Solution 
{
    private boolean isValid(int[] A, int index)
    {
        return A[index] - A[index - 1] == A[index - 1] - A[index - 2];
    }
    
    private int getNumOfSlice(int len)
    {
        if(len < 3)
            return 0;
        int res = 1;
        for(int i = 4; i <= len; i++)
            res = res + i - 2;
        return res;
    }
    
    public int numberOfArithmeticSlices(int[] A)
    {
        if(A.length < 3)
            return 0;

        int current = 0;
        int res = 0;

        for(int i = 2; i < A.length; i++)
        {
            if(isValid(A, i))
                current = current == 0 ? 3 : current + 1;
            else
            {
                res += getNumOfSlice(current);
                current = 0;
            }
        }
        if(current != 0)
            res += getNumOfSlice(current);
        return res;
    }
}