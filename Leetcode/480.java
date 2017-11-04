class Solution 
{
//     private double getMedian(TreeMap<Integer, Integer> map, int k)
//     {
//         int i1, i2;
//         int n1 = 0, n2 = 0;
//         if(k % 2 == 0)
//         {
//             i1 = k / 2;
//             i2 = i1 + 1;
//             for(Integer i : map.keySet())
//             {
//                 i1 -= map.get(i);
//                 if(i1 <= 0)
//                 {
//                     n1 = i;
//                     break;
//                 }
//             }

//             for(Integer i : map.keySet())
//             {
//                 i2 -= map.get(i);
//                 if(i2 <= 0)
//                 {
//                     n2 = i;
//                     break;
//                 }
//             }
            
//             return (n1 * 1.0 + n2) / 2;
//         }
//         else 
//         {
//             i1 = k / 2 + 1;
//             for(Integer i : map.keySet())
//             {
//                 i1 -= map.get(i);
//                 if(i1 <= 0)
//                 {
//                     n1 = i;
//                     break;
//                 }
//             }
//             return n1;
//         }
//     }


//     public double[] medianSlidingWindow(int[] nums, int k)
//     {
//         double[] res = new double[nums.length - k + 1];

//         TreeMap<Integer, Integer> map = new TreeMap<>();
//         for(int i = 0; i < k - 1; i++)
//         {
//             if(map.containsKey(nums[i]))
//                 map.put(nums[i], map.get(nums[i]) + 1);
//             else
//                 map.put(nums[i], 1);
//         }
//         int index = 0;
//         for(int i = k - 1; i < nums.length; i++)
//         {
//             if(map.containsKey(nums[i]))
//                 map.put(nums[i], map.get(nums[i]) + 1);
//             else
//                 map.put(nums[i], 1);
//             res[index++] = getMedian(map, k);
//             if(map.get(nums[i - k + 1]) == 1)
//                 map.remove(nums[i - k + 1]);
//             else
//                 map.put(nums[i - k + 1], map.get(nums[i - k + 1]) - 1);
//         }
        
//         return res;
//     }
    public double[] medianSlidingWindow(int[] nums, int k)
    {
        int n = nums.length;
        int m = n - k + 1;
        double[] res = new double[m];
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(k, Collections.reverseOrder()); //2 heaps, store > mid
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(k); //store < mid
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if(maxHeap.size() == 0 || maxHeap.peek() >= num)
                maxHeap.add(num);
            else
                minHeap.add(num);
            
            if(minHeap.size() > maxHeap.size() )
                maxHeap.add(minHeap.poll());
            if(maxHeap.size() > minHeap.size() + 1 )
                minHeap.add(maxHeap.poll());
            
            if(i - k + 1 >= 0)
            {
                if(k % 2 == 1)
                    res[i - k + 1] = maxHeap.peek();
                else 
                    res[i - k + 1] = (maxHeap.peek() * 1.0 + minHeap.peek()) / 2;
                int toBeRemove = nums[i - k + 1];
                if(toBeRemove <= maxHeap.peek())
                    maxHeap.remove(toBeRemove);
                else
                    minHeap.remove(toBeRemove);
                
                if(minHeap.size() > maxHeap.size())
                    maxHeap.add(minHeap.poll());
                if(maxHeap.size() > minHeap.size() + 1)
                    minHeap.add(maxHeap.poll());

            }
        }
        
        return res;
    }
}