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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) 
    {
        if(t1 == null && t2 == null)
            return null;
        
        TreeNode node = new TreeNode(0);
        if(t1 == null)
            node.val = t2.val;
        else if(t2 == null)
            node.val = t1.val;
        else
            node.val = t1.val + t2.val;
        
        TreeNode t1l = t1 == null ? null : t1.left;
        TreeNode t1r = t1 == null ? null : t1.right;
        TreeNode t2l = t2 == null ? null : t2.left;
        TreeNode t2r = t2 == null ? null : t2.right;
        
        node.left = mergeTrees(t1l, t2l);
        node.right = mergeTrees(t1r, t2r);
        
        return node;
    }
}