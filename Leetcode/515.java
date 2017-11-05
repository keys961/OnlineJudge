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
    public List<Integer> largestValues(TreeNode root)
    {
        List<Integer> res = new ArrayList<>();
        if(root == null)
            return res;
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode node = root;
        TreeNode last = root;
        TreeNode tail = root;
        int rowMax = Integer.MIN_VALUE;
        queue.add(node);
        
        while(!queue.isEmpty())
        {
            node = queue.poll();
            
            if(node.val > rowMax)
                rowMax = node.val;
            
            if(node.left != null)
            {
                queue.add(node.left);
                tail = node.left;
            }
            if(node.right != null) 
            {
                queue.add(node.right);
                tail = node.right;
            }
            
            if(node == last)
            {
                res.add(rowMax);
                rowMax = Integer.MIN_VALUE;
                last = tail;
            }
        }
        
        return res;
    }
}