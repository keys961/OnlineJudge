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
    public TreeNode subtreeWithAllDeepest(TreeNode root) 
    {
        if(root == null)
            return root;
        
        int left = getHeight(root.left);
        int right = getHeight(root.right);
        
        if(left == right)
            return root;
        if(left > right)
            return subtreeWithAllDeepest(root.left);
        return subtreeWithAllDeepest(root.right);
    }
    
    private int getHeight(TreeNode root)
    {
        if(root == null)
            return -1;
        return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
    }
}