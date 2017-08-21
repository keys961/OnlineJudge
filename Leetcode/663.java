import java.util.*;

public class Solution
{
    class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){ val = x; }
    }
    
    private int getSubtreeSum(TreeNode root)
    {
        if(root == null)
            return 0;
        
        return root.val = root.val + getSubtreeSum(root.left) + getSubtreeSum(root.right); 
    }

    public boolean checkEqualTree(TreeNode root)
    {
        if(root == null || (root.left == null && root.right == null))
            return false;
        root.val = getSubtreeSum(root);
        if(root.val % 2 != 0)
            return false;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty())
        {
            TreeNode temp = queue.poll();
            if(temp.val * 2 == root.val)
                return true;
            
            if(temp.left != null)
                queue.add(temp.left);
            if(temp.right != null)
                queue.add(temp.right);
        }
        return false;
    }
}