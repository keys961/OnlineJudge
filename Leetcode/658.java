class Solution 
{
    private void addElement(int[] arr, List<Integer> result, int ptr1, int ptr2, int k, int x)
    {
        while(k > 0)
        {
            if(ptr1 >= 0 && ptr2 < arr.length)
            {
                if(Math.abs(arr[ptr1] - x) > Math.abs(arr[ptr2] - x))
                {
                    result.add(arr[ptr2]);
                    ptr2++;
                }
                else
                {
                    result.add(0, arr[ptr1]);
                    ptr1--;
                }
            }
            else if(ptr1 >= 0)
            {
                result.add(0, arr[ptr1]);
                ptr1--;
            }
            else
            {
                result.add(arr[ptr2]);
                ptr2++;
            }
            k--;
        }
    }
    
    public List<Integer> findClosestElements(int[] arr, int k, int x)
    {
        List<Integer> result = new ArrayList<>(k);
        //sorted array
        int pivot = binarySort(arr, x);
        int ptr1, ptr2;
        if(arr[pivot] == x)
        {
            result.add(x);
            k--;
            ptr1 = pivot - 1;
            ptr2 = pivot + 1;
            addElement(arr, result, ptr1, ptr2, k, x);
        }
        else
        {
            if(arr[pivot] > x)
            {
                ptr1 = pivot - 1;
                ptr2 = pivot;
            }
            else
            {
                ptr1 = pivot;
                ptr2 = pivot + 1;
            }
            addElement(arr, result, ptr1, ptr2, k, x);
        }
        Collections.sort(result);
        return result;
    }
    
    private int binarySort(int[] arr, int x)
    {
        int left = 0, right = arr.length - 1;
        int mid = 0;
        while(left < right)
        {
            mid = (left + right) >> 1;
            if(arr[mid] == x)
                return mid;
            
            if(arr[mid] > x)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        
        return left;
    }
}