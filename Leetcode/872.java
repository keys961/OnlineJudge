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
    private List<Integer> getLeafSequence(TreeNode node, List<Integer> sequence)
    {
        if(node == null)
            return sequence;
        sequence = getLeafSequence(node.left, sequence);
        if(node.left == null && node.right == null)
            sequence.add(node.val);
        sequence = getLeafSequence(node.right, sequence);
        
        return sequence;
    }
    
    public boolean leafSimilar(TreeNode root1, TreeNode root2) 
    {
        List<Integer> seq1 = getLeafSequence(root1, new ArrayList<>());
        List<Integer> seq2 = getLeafSequence(root2, new ArrayList<>());
        
        if(seq1.size() != seq2.size())
            return false;
        
        for(int i = 0; i < seq1.size(); i++)
            if(seq1.get(i) != seq2.get(i))
                return false;
        return true;
    }
}