class Solution
{
	//Slice Window
    public int numSubarrayProductLessThanK(int[] nums, int k)
    {
        int ptr1 = 0, ptr2 = 0;
        if(nums.length <= 0)
            return 0;

        int product = 1, count = 0;
        while(ptr2 < nums.length)
        {
            product *= nums[ptr2];

            while(product >= k && ptr1 <= ptr2)
                product /= nums[ptr1++];
            count += ptr2 - ptr1 + 1;
            ptr2++;
        }

        return count;
    }
}