class Solution 
{
    public boolean increasingTriplet(int[] nums) 
    {
        int low = Integer.MAX_VALUE;
        int mid = Integer.MAX_VALUE;
        
        for(int n : nums)
        {
            if(n <= low)
                low = n; //get arr[i]
            else if(n <= mid)
                mid = n; //get arr[j]
            else
                return true; //get arr[k], done
        }
        
        return false;
    }
}