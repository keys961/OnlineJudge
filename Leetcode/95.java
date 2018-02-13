/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution 
{
    public List<TreeNode> generateTrees(int n)
    {
        // List<TreeNode>[][] dp = new List<>[][];     
        if(n == 0)
            return new ArrayList<TreeNode>();
        List<TreeNode>[][] dp = (List<TreeNode>[][])new ArrayList[n + 1][n + 1];

        for(int step = 0; step < n; step++)
        {
            for(int i = 1; i <= n - step; i++)
            {
                dp[i][i + step] = new ArrayList<TreeNode>();
                if(step == 0)
                {
                    dp[i][i].add(new TreeNode(i));
                    continue;
                }

                for(int root = i; root <= i + step; root++)
                {
                    if(root == i)
                    {
                        for(TreeNode node : dp[root + 1][i + step])
                        {
                            TreeNode rootNode = new TreeNode(root);
                            rootNode.right = node;
                            dp[i][i + step].add(rootNode);
                        }
                    }
                    else if(root == i + step)
                    {
                        for(TreeNode node : dp[i][root - 1])
                        {
                            TreeNode rootNode = new TreeNode(root);
                            rootNode.left = node;
                            dp[i][i + step].add(rootNode);
                        }
                    }
                    else
                    {
                        for(TreeNode left : dp[i][root - 1])
                        {
                            for(TreeNode right : dp[root + 1][i + step])
                            {
                                TreeNode rootNode = new TreeNode(root);
                                rootNode.left = left;
                                rootNode.right = right;
                                dp[i][i + step].add(rootNode);
                            }
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
}