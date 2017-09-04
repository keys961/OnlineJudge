class Solution 
{
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t)
    {
//         if(nums.length == 0 || k <= 0)
//             return false;

//         TreeSet<Integer> set = new TreeSet<>();

//         for(int i = 0; i < nums.length; i++)
//         {
//             final Integer low = set.floor(nums[i] + t);
//             final Integer up = set.ceiling(nums[i] - t);

//             if((low != null && low >= nums[i])
//                     || (up != null && up <= nums[i]))
//                 return true;
//             set.add(nums[i]);
//             if(i >= k)
//                 set.remove(nums[i - k]);
//         }

//         return false;
        
    if(nums.length == 0 || k <= 0)
        return false;

    List<Long> list = new ArrayList<>();
    for(int n : nums)
        list.add((long)n);

    TreeSet<Long> set = new TreeSet<>();
    for(int i = 0; i < nums.length; i++)
    {
        Long low = set.floor(list.get(i) + t);
        Long up = set.ceiling(list.get(i) - t);

        if(low != null && low >= list.get(i)
                || up != null && up <= list.get(i))
            return true;
        set.add(list.get(i));
        if(i >= k)
            set.remove(list.get(i - k));
    }

    return false;
    

    }
}