import java.util.*;

public class Solution
{
    public class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private void traversal(TreeNode root, Set<Integer> set)
    {
        if(root == null)
            return;

        traversal(root.left, set);
        set.add(root.val);
        traversal(root.right, set);
    }

    public boolean findTarget(TreeNode root, int k)
    {
        Set<Integer> set = new TreeSet<>();
        traversal(root, set);
        Integer[] array = new Integer[set.size()];
        array = set.toArray(array);
        int low = 0, up = array.length - 1;
        while(low < up)
        {
            if(array[low] + array[up] < k)
                low++;
            else if(array[low] + array[up] > k)
                up--;
            else
                return true;
        }
        return false;
    }
}