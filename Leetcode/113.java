import java.util.*;

public class Solution
{
    List<List<Integer>> lists = new ArrayList<>();

    private void helper(TreeNode node, int sum, List<Integer> list)
    {
        if(node == null)
            return;
        if(node.left == null && node.right == null)
        {
            if(node.val == sum)
            {
                list.add(node.val);
                lists.add(list);
            }
            return;
        }

        if(node.left != null)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(node.val);
            helper(node.left, sum - node.val, newList);
        }

        if(node.right != null)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(node.val);
            helper(node.right, sum - node.val, newList);
        }
    }


    public List<List<Integer>> pathSum(TreeNode root, int sum)
    {
        helper(root, sum, new ArrayList<>());
        return lists;
    }
}