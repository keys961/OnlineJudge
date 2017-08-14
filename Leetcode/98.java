public class Solution
{
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private int findMax(TreeNode root)
    {
        while(root.right != null)
            root = root.right;
        return root.val;
    }

    private int findMin(TreeNode root)
    {
        while(root.left != null)
            root = root.left;
        return root.val;
    }

    public boolean isValidBST(TreeNode root)
    {
        if(root == null || (root.left == null && root.right == null))
            return true;

        long leftMax = root.left == null ? Long.MIN_VALUE : findMax(root.left);
        long rightMin = root.right == null ? Long.MAX_VALUE : findMin(root.right);

        return isValidBST(root.left) && isValidBST(root.right) &&
                (leftMax < root.val && rightMin > root.val);
    }
}