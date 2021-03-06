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

    public List<List<Integer>> levelOrder(TreeNode root)
    {
        List<List<Integer>> lists = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        if(root == null)
            return lists;
        TreeNode lastNode = root;
        TreeNode tail = root;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty())
        {
            TreeNode temp = queue.poll();
            list.add(temp.val);
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
            if(temp == lastNode)
            {
                lastNode = tail;
                lists.add(list);
                list = new ArrayList<>();
            }
        }
        return lists;
    }
}