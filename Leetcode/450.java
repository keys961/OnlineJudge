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
    public TreeNode deleteNode(TreeNode root, int key) 
    {
        if(root == null)
            return root;
        
        if(key > root.val)
            root.right = deleteNode(root.right, key);
        else if(key < root.val)
            root.left = deleteNode(root.left, key);
        else //equal
        {
            if(root.left != null && root.right != null)
            {
                int nextKey = findMin(root.right);
                root.right = deleteNode(root.right, nextKey);
                root.val = nextKey;
            }
            else if(root.left != null)
                root = root.left;
            else root = root.right;
        }
        
        return root;
    }
    
    private int findMin(TreeNode root)
    {
        if(root == null)
            return Integer.MIN_VALUE;
        while(root.left != null)
            root = root.left;
        
        return root.val;
    }

}