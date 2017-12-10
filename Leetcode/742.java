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
    private List<TreeNode> leafNodes = new ArrayList<>();

    private TreeNode targetNode = null;

    private void traversal(TreeNode node, int k)
    {
        if(node == null)
            return;

        if(node.left == null && node.right == null)
            leafNodes.add(node);

        if(node.val == k)
            targetNode = node;

        traversal(node.left, k);
        traversal(node.right, k);
    }

    private List<TreeNode> path = new ArrayList<>();

    private void getPath(TreeNode node, TreeNode target, List<TreeNode> path)
    {
        if(node == target)
        {
            this.path = new ArrayList<>(path);
            return;
        }

        if(node == null)
            return;

        if(node.left != null)
        {
            path.add(node.left);
            getPath(node.left, target, path);
            path.remove(path.size() - 1);
        }

        if(node.right != null)
        {
            path.add(node.right);
            getPath(node.right, target, path);
            path.remove(path.size() - 1);
        }
    }

    private TreeNode findLCA(TreeNode root, TreeNode p, TreeNode q)
    {
        TreeNode res = root;

        List<TreeNode> pathP;
        List<TreeNode> pathQ;;
        List<TreeNode> tempList = new ArrayList<>();

        tempList.add(root);

        getPath(root, p, tempList);
        pathP = path;
        getPath(root, q, tempList);
        pathQ = path;

        int len = Math.min(pathP.size(), pathQ.size());

        for(int i = 0; i < len; i++)
        {
            if(pathP.get(i) == pathQ.get(i))
                res = pathP.get(i);
        }

        return res;
    }

    private int getLevel(TreeNode root, TreeNode p)
    {
        LinkedList<TreeNode> queue = new LinkedList<>();
        TreeNode lastNode = root;
        queue.add(root);
        int level = 0;

        while(!queue.isEmpty())
        {
            TreeNode temp = queue.pollFirst();
            if(temp == p)
                return level;

            if(temp.left != null)
                queue.add(temp.left);
            if(temp.right != null)
                queue.add(temp.right);

            if(lastNode == temp)
            {
                level++;
                if(!queue.isEmpty())
                    lastNode = queue.getLast();
            }
        }

        return level;
    }

    // private TreeNode findLCA(TreeNode root, TreeNode p, TreeNode q) //another way is to traversal the path from root and get LCA ...
    // {
    // 	if(root == null)
    // 		return null;
    // 	// if node_p is at sub-tree root, it must be no-null
    //     if(root == p || root == q) //root is LCA itself
    //         return root;
        
    //     TreeNode left = findLCA(root.left, p, q);
    //     TreeNode right = findLCA(root.right, p, q);

    //     if(left != null && right != null) //at both sides
    //     	return root;
    //     else if(left != null) //both in left sub-tree
    // 		return left;
    // 	else if(right != null) //both in right sub-tree
    // 		return right;
    // 	else
    // 		return null
    // }

    public int findClosestLeaf(TreeNode root, int k)
    {
        int dist = Integer.MAX_VALUE;
        TreeNode leaf = null;
        traversal(root, k);
        int levelTarget = getLevel(root, targetNode);

        for(TreeNode node : leafNodes)
        {
            TreeNode lca = findLCA(root, node, targetNode);
            int levelLCA = getLevel(root, lca);
            int levelNode = getLevel(root, node);
            int tempDist = levelTarget + levelNode - 2 *levelLCA;
            if(tempDist < dist)
            {
                leaf = node;
                dist = tempDist;
            }
        }

        return leaf.val;
    }
}