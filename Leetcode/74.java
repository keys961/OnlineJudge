import java.util.*;

public class Solution
{
    public boolean searchMatrix(int[][] matrix, int target)
    {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;
        if(matrix.length == 1)
            return Arrays.binarySearch(matrix[0], target) >= 0;

        int low = 0, high = matrix.length - 1, mid = 0;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(matrix[mid][0] > target)
                high = mid - 1;
            else
            {
                if(matrix[mid][0] == target)
                    return true;
                if(mid < matrix.length - 1 && matrix[mid + 1][0] > target)
                    break;
                else if(mid < matrix.length - 1 && matrix[mid + 1][0] == target)
                    return true;
                else if(mid < matrix.length - 1 && matrix[mid + 1][0] < target)
                    low = mid + 1;
                else
                    break;
            }
        }
        return Arrays.binarySearch(matrix[mid], target) >= 0;
    }
}