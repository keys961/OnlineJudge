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
    private String printTree(TreeNode node)
    {
        StringBuilder s = new StringBuilder("(");
        if(node == null)
        {
            s.append(")");
            return s.toString();
        }
        s.append(node.val);
        if(node.right != null) 
        {
            s.append(printTree(node.left));
            s.append(printTree(node.right));
        }
        else if(node.left != null)
            s.append(printTree(node.left));
        s.append(")");
        return s.toString();
    }

    public String tree2str(TreeNode t)
    {
        if(t == null)
            return "";
        String res = Integer.toString(t.val);
        if(t.right != null)
        {
            res += printTree(t.left);
            res += printTree(t.right);
        }
        else if(t.left != null)
            res += printTree(t.left);
        return res;
    }
}