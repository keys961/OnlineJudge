public class Solution
{
    public int maxArea(int[] height)
    {   //2 Pointer
        int start = 0, end = height.length - 1;
        int res = 0;
        while(start < end)
        {
            int temp = Math.min(height[start], height[end]) * (end - start);
            res = Math.max(res, temp);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return res;
    }
}