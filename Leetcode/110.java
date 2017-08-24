class Solution 
{
    private int getHeight(TreeNode node)
    {
        if(node == null)
            return -1;
        
        return Math.max(getHeight(node.left), 
                getHeight(node.right)) + 1;
    }
    
    public boolean isBalanced(TreeNode root)
    {
        if(root == null)
            return true;
        if(Math.abs(getHeight(root.left) - getHeight(root.right)) > 1)
            return false;
        return isBalanced(root.left) && isBalanced(root.right);
    }
}