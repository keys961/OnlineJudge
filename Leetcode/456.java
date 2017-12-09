class Solution 
{
    public boolean find132pattern(int[] nums)  //very naive solution
    {
        boolean status = false;
        int i = 0;
        while(i < nums.length - 2 && !status)
        {
            while(i < nums.length - 3 && nums[i + 1] <= nums[i])
                i++;
            LinkedList<Integer> list = new LinkedList<>();
            list.add(nums[i]);
            list.add(nums[i + 1]);
            for(int j = i + 2; j < nums.length && !status; j++)
            {
                if(list.size() == 2) 
                {
                    if (nums[j] >= list.getLast()) 
                    {
                        list.removeLast();
                        list.add(nums[j]);
                    }
                    else
                    {
                        if(nums[j] > nums[i])
                        {
                            list.add(nums[j]);
                            status = true;
                            break;
                        }
                    }
                }
            }
            i++;
        }

        return status;
    }
}