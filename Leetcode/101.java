public class Solution
{
    public class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private boolean isSameTree(TreeNode p, TreeNode q)
    {
        if(p == null && q == null)
            return true;
        if(p != null && q == null || p == null && q != null || p.val != q.val)
            return false;

        return isSameTree(p.left, q.right) && isSameTree(p.right, q.left);
    }

    public boolean isSymmetric(TreeNode root)
    {
        if(root == null)
            return true;
        return isSameTree(root.left, root.right);
    }
}