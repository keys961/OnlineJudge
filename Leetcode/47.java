public class Solution 
{
   List<List<Integer>> result = new ArrayList<>();

    boolean[] visited;
    List<Integer> tempList = new ArrayList<>();

    public List<List<Integer>> permuteUnique(int[] nums)
    {

        if(nums.length == 0)
            return result;
        Arrays.sort(nums);
        visited = new boolean[nums.length];
        getOnePermute2(nums, visited, tempList);
        return result;
    }

    private void getOnePermute2(int[] nums, boolean[] visited, List<Integer> list)
    {
        if(list.size() == nums.length)
        {
            if(!result.contains(list))
                result.add(new ArrayList<>(list));
            return;
        }

        for(int i = 0; i < nums.length; i++)
        {
            if(i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) //Skip the same value
                continue;
            if(!visited[i])
            {
                visited[i] = true;
                tempList.add(nums[i]);
                getOnePermute2(nums, visited, tempList);
                visited[i] = false;
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}