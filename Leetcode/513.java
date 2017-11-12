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
    public int findBottomLeftValue(TreeNode root) 
    {
        LinkedList<TreeNode> queue = new LinkedList<>();
        TreeNode node = root;
        TreeNode last = root;
        int levelCount = 0;
        int res = 0;
        
        queue.addLast(root);
        
        while(!queue.isEmpty())
        {
            node = queue.pollFirst();
            levelCount++;
            if(levelCount == 1)
                res = node.val;
            
            if(node.left != null)
                queue.addLast(node.left);
            if(node.right != null)
                queue.addLast(node.right);
            
            if(node == last)
            {
                levelCount = 0;
                if(!queue.isEmpty())
                    last = queue.getLast();
            }
        }
        
        return res;
    }
}