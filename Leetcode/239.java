class Solution 
{
    public int[] maxSlidingWindow(int[] nums, int k)
    {
        //Another heap example!!, if you want median, use 2 heaps!
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
        	(o1, o2) -> {return o2 - o1;}	
        );
        if(nums.length < k || k == 0)
            return new int[0];
        int[] list = new int[nums.length - k + 1];
        for(int i = 0; i < k; i++)
            maxHeap.add(nums[i]);
        list[0] = maxHeap.peek();
        for(int i = k; i < nums.length; i++)
        {
            maxHeap.remove(nums[i - k]);
            maxHeap.add(nums[i]);
            list[i - k + 1] = maxHeap.peek();
        }
        
        return list;
    }
}