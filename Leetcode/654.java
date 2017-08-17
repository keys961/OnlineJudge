public class Solution
{

    public class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private TreeNode construct(int[] nums, int low, int up)
    {
        if(low == up)
            return new TreeNode(nums[low]);
        if(low > up)
            return null;

        int maxVal = Integer.MIN_VALUE;
        int rootIndex = -1;
        for(int i = low; i <= up; i++)
        {
            if(nums[i] >= maxVal)
            {
                rootIndex = i;
                maxVal = nums[i];
            }
        }

        TreeNode root = new TreeNode(maxVal);
        root.left = construct(nums, low, rootIndex - 1);
        root.right = construct(nums, rootIndex + 1, up);

        return root;
    }

    public TreeNode constructMaximumBinaryTree(int[] nums)
    {
        return construct(nums, 0, nums.length - 1);
    }
}