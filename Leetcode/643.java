class Solution 
{
    public double findMaxAverage(int[] nums, int k) 
    {
        if(nums.length < k)
            return 0.0;
        double sum = 0;
        for(int i = 0; i < k; i++)
            sum += nums[i];
        double avg = sum / k;
        
        for(int i = k; i < nums.length; i++)
        {
            sum -= nums[i - k];
            sum += nums[i];
            
            if(sum / k > avg)
                avg = sum / k;
        }
        
        return avg;
    }
}