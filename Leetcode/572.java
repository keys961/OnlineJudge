class Solution 
{
    private boolean isSameTree(TreeNode a, TreeNode b)
    {
        if(a == null && b == null)
            return true;
        
        if(a == null || b == null)
            return false;
        
        if(a.val != b.val)
            return false;
        
        return isSameTree(a.left, b.left) && isSameTree(a.right, b.right);
    }

    public boolean isSubtree(TreeNode s, TreeNode t)
    {
        if(s == null)
            return false;
        if(isSameTree(s, t))
            return true;
        
        boolean left = false;
        boolean right = false;
        
        //if(s.left != null)
            left = isSubtree(s.left, t);
       // if(s.right != null)
            right = isSubtree(s.right, t);
        
        return left || right;
    }
}