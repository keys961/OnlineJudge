class Solution
{
    private List<String> res = new ArrayList<>();
    
    private void traversal(TreeNode root, List<Integer> list)
    {
        if(root.left == null && root.right == null)
        {
            res.add(getString(list));
            return;
        }
        
        if(root.left != null)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(root.left.val);
            traversal(root.left, newList);
        }
        
        if(root.right != null)
        {
            List<Integer> newList = new ArrayList<>(list);
            newList.add(root.right.val);
            traversal(root.right, newList);
        }
    }
    
    private String getString(List<Integer> list)
    {
        if(list.size() == 0)
            return "";
        String res = list.get(0).toString();
        for(int i = 1; i < list.size(); i++)
            res += "->" + list.get(i).toString();
        return res;
    }
    
    public List<String> binaryTreePaths(TreeNode root) 
    {
        if(root == null)
            return res;
        List<Integer> list = new ArrayList<>();
        list.add(root.val);
        traversal(root, list);
        return res;
    }
}