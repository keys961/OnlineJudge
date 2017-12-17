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
    
    private Integer previous = null;
    
    private int maxDiff = Integer.MAX_VALUE;
    
    private void inorderTraversals(TreeNode node)
    {
        if(node == null)
            return;
        
        inorderTraversals(node.left);
        if(previous != null)
        {
            int diff = (node.val - previous);
            if(diff < maxDiff)
                maxDiff = diff;
        }
        previous = node.val;
        
        inorderTraversals(node.right);
    }
    
    public int getMinimumDifference(TreeNode root)
    {
        inorderTraversals(root);
        return maxDiff;
    }
}