public class Solution
{

    public class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    
    private TreeNode helper(int[] preorder, int[] inorder,
                            int preStart, int preEnd,
                            int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd)
            return null;
        if(preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        int rootVal = preorder[preStart];
        int rootIndex = 0;
        for(int i = inStart; i <= inEnd; i++)
            if(inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        int leftNum = rootIndex - inStart;
        TreeNode root = new TreeNode(rootVal);
        root.left = helper(preorder, inorder, preStart + 1, preStart + leftNum,
                inStart, rootIndex - 1);
        root.right = helper(preorder, inorder, preStart + leftNum + 1, preEnd, rootIndex + 1, inEnd);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder)
    {
        return  helper(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
    }
}