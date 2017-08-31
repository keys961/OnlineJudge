import java.util.*;

public class Solution
{
    public int[] twoSum(int[] numbers, int target)
    {
        int[] res = new int[2];

        for(int i = 0; numbers[i] <= target / 2 && i < numbers.length; i++)
        {
            int temp = target - numbers[i];
            int index = Arrays.binarySearch(numbers, temp);
            if(index == i)
                index = Arrays.binarySearch(numbers, index + 1, numbers.length, temp);
            if(index >= 0)
            {
                res[0] = i + 1;
                res[1] = index + 1;
                break;
            }
        }
        return res;
    }
}