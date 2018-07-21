class Solution 
{
    public int peakIndexInMountainArray(int[] A) 
    {
        int maxIndex = -1;
        int max = -1;
        for(int i = 0; i < A.length; i++)
        {
            if(A[i] > max)
            {
                max = A[i];
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
}