class Solution 
{
    private int getSumOfTree(TreeNode node)
    {
        if(node == null)
            return 0;
        return node.val + getSumOfTree(node.left) + getSumOfTree(node.right);
    }
    
    public int findTilt(TreeNode root)
    {
        if(root == null)
            return 0;
        int val = (int)Math.abs(getSumOfTree(root.left) - getSumOfTree(root.right));
        return val + findTilt(root.left) + findTilt(root.right);
    }
}