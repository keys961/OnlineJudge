/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) 
    {
        if(root == null)
            return "null";
        
        String rootVal = String.valueOf(root.val);
        rootVal = rootVal + " " + serialize(root.left);
        rootVal = rootVal + " " + serialize(root.right);
        
        return rootVal;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) 
    {
        String[] node = data.split("\\s+");
        return helper(node, new int[]{0});
    }
    
    private TreeNode helper(String[] node, int[] i)
    {
        if(node[i[0]].equals("null"))
        {
            i[0]++;
            return null;
        }
        TreeNode n = new TreeNode(Integer.parseInt(node[i[0]++]));
        n.left = helper(node, i);
        n.right = helper(node, i);
        
        return n;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));