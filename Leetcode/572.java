/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution
{
    private boolean isSame(TreeNode t1, TreeNode t2)
    {
        if(t1 == null && t2 == null)
            return true;
        if(t1 == null || t2 == null)
            return false;
        
        if(t1.val != t2.val)
            return false;
        return isSame(t1.left, t2.left) && isSame(t1.right, t2.right);
    }
    
    public boolean isSubtree(TreeNode s, TreeNode t) 
    {
        if(s == null && t == null)
            return true;
        if(s == null)
            return false;
        if(t == null)
            return true;
        
        boolean status = false;
        if(s.val == t.val)
            status = isSame(s, t);
        
        return status || (isSubtree(s.left, t) || isSubtree(s.right, t));
    }
}