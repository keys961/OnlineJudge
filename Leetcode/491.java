class Solution
{
    private Set<List<Integer>> res = new HashSet<>();//Use set if there are duplicates

    private void helper(int[] nums, int index, List<Integer> list)
    {
        if(list.size() >= 2)
        {
            List<Integer> newList = new ArrayList<>(list);
            res.add(newList);
        }
        
        for(int i = index + 1; i < nums.length; i++)
        {
            if(list.get(list.size() - 1) <= nums[i])
            {
                list.add(nums[i]);
                helper(nums, i, list);
                list.remove(list.size() - 1);
            }
        }
    }

    public List<List<Integer>> findSubsequences(int[] nums)
    {
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < nums.length; i++)
        {
            list.add(nums[i]);
            helper(nums, i, list);
            list.remove(list.size() - 1);
        }

        return new ArrayList<>(res);
    }
}