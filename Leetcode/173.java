public class BSTIterator
{
    //Iterative Inorder traversal
    
    private Stack<TreeNode> stack = new Stack<>();
    
    public BSTIterator(TreeNode root)
    {
        while(root != null)
        {
            stack.push(root);
            root = root.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext()
    {
        return !stack.isEmpty();
    }

    /** @return the next smallest number */
    public int next()
    {
        TreeNode node = stack.pop();
        int res = node.val;
        node = node.right;
        while(node != null)
        {
            stack.push(node);
            node = node.left;
        }
        return res;
    }
}