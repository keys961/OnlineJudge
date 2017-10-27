class Solution 
{
    private Set<Integer> set = new TreeSet<>();

    private void traversal(TreeNode node)
    {
        if(node == null)
            return;
        
        set.add(node.val);
        traversal(node.left);
        traversal(node.right);
    }
    
    public int findSecondMinimumValue(TreeNode root)
    {
        traversal(root);
        int cnt = 0;
        for(int i : set)
        {
            if(cnt == 1)
                return i;
            cnt++;
        }
        return -1;
    }
}