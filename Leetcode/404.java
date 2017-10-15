class Solution 
{
    int sum = 0;
    
    private void traversal(TreeNode node)
    {
        if(node == null)
            return;
        
        if(node.left == null && node.right == null)
            return;
        
        if(node.left != null && node.left.left == null && node.left.right == null)
            sum += node.left.val;
        
        traversal(node.left);
        traversal(node.right);
    }
    
    public int sumOfLeftLeaves(TreeNode root)
    {
        if(root == null)
            return 0;
        if(root.left == null && root.right == null)
            return 0;
        
        traversal(root);
        return sum;
    }
}