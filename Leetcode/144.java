import java.util.*;

public class Solution
{
    public List<Integer> preorderTraversal(TreeNode root)
    {

        Stack<TreeNode> stack = new Stack<>();
        List<Integer> list = new ArrayList<>();

        if(root == null)
            return list;
        TreeNode temp = root;
        while(!stack.isEmpty() || temp != null)
        {
            while (temp != null)
            {
                stack.push(temp);
                list.add(temp.val);
                temp = temp.left;
            }
            temp = stack.pop();
            temp = temp.right;
        }

        return list;
    }
}