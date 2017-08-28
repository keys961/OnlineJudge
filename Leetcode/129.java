public class Solution
{
    private int result = 0;

    private void helper(TreeNode node, int value)
    {
        if(node.left == null && node.right == null)
        {
            result += value;
            return;
        }

        if(node.left != null)
            helper(node.left, value * 10 + node.left.val);
        if(node.right != null)
            helper(node.right, value * 10 + node.right.val);
    }

    public int sumNumbers(TreeNode root)
    {
        if(root == null)
            return 0;
        helper(root, root.val);
        return result;
    }
}