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
    public List<Double> averageOfLevels(TreeNode root) 
    {
        LinkedList<TreeNode> queue = new LinkedList<>();
        List<Double> res = new ArrayList<>();
        
        TreeNode node = root;
        TreeNode last = root;
        double sum = 0;
        int count = 0;
        
        queue.addLast(node);
        
        while(!queue.isEmpty())
        {
            node = queue.pollFirst();
            sum += node.val;
            count++;
            
            if(node.left != null)
                queue.addLast(node.left);
            if(node.right != null)
                queue.addLast(node.right);
            
            if(node == last)
            {
                if(!queue.isEmpty())
                    last = queue.getLast();
                res.add(sum / count);
                sum = 0;
                count = 0;
            }
        }
        
        return res;
    }
}