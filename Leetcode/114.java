import java.util.*;

public class Solution
{
    public void flatten(TreeNode root)
    {
        if(root == null)
            return;
        Stack<TreeNode> stack = new Stack<>();
        List<TreeNode> list = new ArrayList<>();

        TreeNode temp = root;
        while(!stack.isEmpty() || temp != null)
        {
            while (temp != null)
            {
                stack.push(temp);
                list.add(temp);
                temp = temp.left;
            }
            temp = stack.pop();
            temp = temp.right;
        }

        for(int i = 0; i < list.size() - 1; i++)
        {
            list.get(i).left = null;
            list.get(i).right = list.get(i + 1);
        }

        list.get(list.size() - 1).left =
                list.get(list.size() - 1).right = null;

        root = list.get(0);
        return;
    }
}