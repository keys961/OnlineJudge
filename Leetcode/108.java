public class Solution
{

    public class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    
    private TreeNode buildTree(int[] nums, int left, int right)
    {
        if(left > right)
            return null;
        if(left == right)
            return new TreeNode(nums[left]);

        int mid = (left + right) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = buildTree(nums, left, mid - 1);
        root.right = buildTree(nums, mid + 1, right);
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums)
    {
        if(nums.length == 0)
            return null;
        return buildTree(nums, 0, nums.length - 1);
    }
}