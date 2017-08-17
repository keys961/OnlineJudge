public class Solution
{

    List<List<Integer>> result = new ArrayList<>();

    private void getOnePermute(int[] nums, List<Integer> list)
    {
        if(list.size() == nums.length)
        {
            result.add(list);
            return;
        }

        for(int i = 0; i < nums.length; i++)
        {
            List<Integer> newList = new ArrayList<>(list);
            if(!newList.contains(nums[i]))
            {
                newList.add(nums[i]);
                getOnePermute(nums, newList);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums)
    {
        if(nums.length == 0)
            return result;
        getOnePermute(nums, new ArrayList<>());
        return result;
    }
    
}