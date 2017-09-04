import java.util.*;

public class Solution
{
    // public int findKthLargest(int[] nums, int k)
    // {
    //     PriorityQueue<Integer> queue = new PriorityQueue<>(
    //             new Comparator<Integer>() {
    //                 @Override
    //                 public int compare(Integer o1, Integer o2) {
    //                     return o2 - o1;
    //                 }
    //             }
    //     );
    //     for(int i = 0; i < nums.length; i++)
    //         queue.add(nums[i]);
    //     int res = 0;
    //     for(int i = 0; i < k; i++)
    //         res = queue.poll();
    //     return res;
    // }

	private void buildHeap(int[] nums, int n)
    {
        int index = n / 2 - 1;
        for(; index >= 0; index--)
            percDown(nums, index, n);
    }

    private void percDown(int[] nums, int index, int n)
    {
        int tempVal = nums[index];
        int current = index;
        while(current * 2 + 1 < n)
        {
            int child = current * 2 + 1;
            if (child < n - 1 && nums[child + 1] > nums[child])
                child++;
            if (tempVal < nums[child])
            {
                nums[current] = nums[child];
                current = child;
            }
            else
                break;
        }
        nums[current] = tempVal;
    }

    private int poll(int[] heap, int n)
    {
        int res = heap[0];
        heap[0] = heap[n - 1];
        percDown(heap, 0, n - 1);
        return res;
    }

    public int findKthLargest(int[] nums, int k)
    {
        buildHeap(nums, nums.length);
        int res = 0;
        int len = nums.length;
        for(int i = 0; i < k; i++)
            res = poll(nums, len--);
        return res;
    }

}