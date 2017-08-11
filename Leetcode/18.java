import java.util.*;

public class Solution
{
    public List<List<Integer>> fourSum(int[] nums, int target)
    {
        List<List<Integer>> lists = new LinkedList<>();
        Arrays.sort(nums);
        if(nums.length < 4)
            return lists;
        int newTarget, high, low;
        for(int i = 0; i < nums.length - 3; i++)
        {
            for(int j = i + 1; j < nums.length - 2; j++)
            {
                if(nums[j - 1] == nums[j] && j != i + 1)
                    continue;
                newTarget = target - (nums[i] + nums[j]);
                low = j + 1;
                high = nums.length - 1;
                while(low < high)
                {
                    if(nums[low] + nums[high] < newTarget)
                        low++;
                    else if(nums[low] + nums[high] > newTarget)
                        high--;
                    else
                    {
                        List<Integer> list = Arrays.asList(nums[i], nums[j], nums[low], nums[high]);
                        if(!lists.contains(list))
                            lists.add(list);
                        while (low < high && nums[low + 1] == nums[low])
                            low++;
                        while(low < high && nums[high - 1] == nums[high])
                            high--;
                        low++;
                        high--;
                    }
                }

            }
        }
        return lists;
    }
}