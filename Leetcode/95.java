public class Solution
{
    private TreeNode helper(TreeNode node, int offset)
    {
        if(node == null)
            return null;

        TreeNode root = new TreeNode(node.val + offset);
        root.left = helper(node.left, offset);
        root.right = helper(node.right, offset);
        return root;
    }

    public List<TreeNode> generateTrees(int n)
    {
        List<TreeNode>[] resultList = new List[n + 1];
        resultList[0] = new ArrayList<>();
        if(n == 0)
            return resultList[0];

        resultList[0].add(null);
        for(int i = 1; i <= n; i++) // i : Number of nodes in the tree
        {
            resultList[i] = new ArrayList<>();
            for(int j = 0; j < i; j++) //j + 1: Root, j: left node number
            {
                for(TreeNode leftTree : resultList[j])
                {
                    for(TreeNode rightTree : resultList[i - j - 1])
                    {
                        TreeNode root = new TreeNode(j + 1);
                        root.left = leftTree;
                        root.right = helper(rightTree, j + 1);
                        resultList[i].add(root);
                    }
                }
            }
        }
        return resultList[n];
    }
}