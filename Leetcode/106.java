public class Solution
{

    public class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    
    private TreeNode helper(int[] postorder, int[] inorder,
                            int postStart, int postEnd,
                            int inStart, int inEnd)
    {
        if(inStart > inEnd)
            return null;
        if(inStart == inEnd)
            return new TreeNode(postorder[postEnd]);

        int rootVal = postorder[postEnd];
        int rootIndex = 0;
        for(int i = inStart; i <= inEnd; i++)
            if(inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        int rightNum = inEnd - rootIndex;
        TreeNode root = new TreeNode(rootVal);
        root.left = helper(postorder, inorder, postStart, postEnd - rightNum - 1,
                inStart, rootIndex - 1);
        root.right = helper(postorder, inorder, postEnd - rightNum, postEnd - 1, rootIndex + 1, inEnd);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder)
    {
        return helper(postorder, inorder, 0, postorder.length - 1,
                0, inorder.length - 1);
    }
}