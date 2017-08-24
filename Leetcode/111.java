import java.util.*;

public class Solution
{
    public int minDepth(TreeNode root)
    {
        Queue<TreeNode> queue = new LinkedList<>();
        if(root == null)
            return 0;
        int level = 1;
        TreeNode tail = root, end = root;
        queue.add(root);
        while(!queue.isEmpty())
        {
            TreeNode temp = queue.poll();
            if(temp.left == null && temp.right == null)
                return level;
            if(temp.left != null)
            {
                tail = temp.left;
                queue.add(temp.left);
            }
            if(temp.right != null)
            {
                tail = temp.right;
                queue.add(temp.right);
            }
            if(temp == end)
            {
                level++;
                end = tail;
            }
        }
        return level;
    }
}