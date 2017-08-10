import java.util.*;

public class Solution
{
    public List<List<Integer>> threeSum(int[] nums)
    {
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<>();
        for(int i = 0; i < nums.length - 2; i++)
        {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.length - 1;
            int sum = -nums[i];
            while(j < k)
            {
                if(nums[j] + nums[k] > sum)
                    k--;
                else if(nums[j] + nums[k] < sum)
                    j++;
                else
                {
                    list.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    while(j < k && nums[j] == nums[j + 1])
                        j++;
                    while(j < k && nums[k - 1] == nums[k])
                        k--;
                    j++; k--;
                }
            }
        }
        return list;
    }
}