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

    public List<List<Integer>> zigzagLevelOrder(TreeNode root)
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
        for(int i = 0; i < lists.size(); i++)
            if(i % 2 != 0)
                Collections.reverse(lists.get(i));
        return lists;
    }
}