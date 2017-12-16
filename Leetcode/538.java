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
    private List<TreeNode> traversals = new ArrayList<>();
    
    private void inorderTraversal(TreeNode node)
    {
        if(node == null)
            return;
        
        inorderTraversal(node.right);
        traversals.add(node);
        inorderTraversal(node.left);
    }
    
    public TreeNode convertBST(TreeNode root) 
    {
        inorderTraversal(root);
        int sum = 0, temp;
        for(TreeNode node : traversals)
        {
            temp = node.val;
            node.val += sum;
            sum += temp;
            
        }
        
        return root;
    }
}