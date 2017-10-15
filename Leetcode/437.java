class Solution
{
    int res = 0;
    
    List<TreeNode> list = new ArrayList<>();
    
    private void helper(TreeNode node, int sum)
    {
        // if(sum < 0)
        //     return;
        if(sum == 0)
        {
            res++;
           // return;
        }
        
        if(node.left != null)
            helper(node.left, sum - node.left.val);
        if(node.right != null)
            helper(node.right, sum - node.right.val);
    }
    
    private void traversal(TreeNode node)
    {
        if(node == null)
            return;
        
        list.add(node);
        traversal(node.left);
        traversal(node.right);
    }
    
    public int pathSum(TreeNode root, int sum)
    {
        traversal(root);
        if(list.size() == 0)
            return 0;
        
        for(TreeNode node : list)
            helper(node, sum - node.val);
        
        return res;
    }
}