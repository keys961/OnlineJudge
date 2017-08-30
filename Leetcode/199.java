import java.util.*;

public class Solution
{
    public List<Integer> rightSideView(TreeNode root)
    {
        List<Integer> list = new ArrayList<>();
        if(root == null)
            return list;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        TreeNode last = root, tail = root;

        while(!queue.isEmpty())
        {
            TreeNode temp = queue.poll();
            if(temp.left != null)
            {
                queue.add(temp.left);
                tail = temp.left;
            }
            if(temp.right != null)
            {
                queue.add(temp.right);
                tail = temp.right;
            }
            if(last == temp)
            {
                list.add(temp.val);
                last = tail;
            }
        }
        return list;
    }
}