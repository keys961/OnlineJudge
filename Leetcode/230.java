import java.util.*;

public class Solution
{
    public int kthSmallest(TreeNode root, int k)
    {
        Stack<TreeNode> stack = new Stack<>();
        int result = -1;
        TreeNode temp = root;

        while(!stack.isEmpty() || temp != null)
        {
            while(temp != null)
            {
                stack.push(temp);
                temp = temp.left;
            }
            temp = stack.pop();
            result = temp.val;
            k--;
            if(k == 0)
                break;
            temp = temp.right;
        }

        return result;
    }
}