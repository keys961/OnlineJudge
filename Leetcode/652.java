class Solution
{

    private Map<String, List<TreeNode>> nodeMap = new HashMap<>();

    private List<TreeNode> ans = new ArrayList<>();

    private String serializeTree(TreeNode node) //Serialize the tree as the key -> value: list of node
    {   
        if(node == null)
            return "null";

        String res =  "( " + serializeTree(node.left) + " " + node.val + " " + serializeTree(node.right) + " )";
        if(nodeMap.containsKey(res))
        {
            List<TreeNode> list = nodeMap.get(res);
            list.add(node);
            nodeMap.put(res, list);//Serialization with map building...
        }
        else
        {
            List<TreeNode> list = new ArrayList<>();
            list.add(node);
            nodeMap.put(res, list);//Serialization with map building...
        }

        return res;
    }


    public List<TreeNode> findDuplicateSubtrees(TreeNode root)
    {
        if(root == null)
            return ans;

        serializeTree(root);
        for(String s : nodeMap.keySet())
        {
            if(nodeMap.get(s).size() >= 2)
                ans.add(nodeMap.get(s).get(0));
        }
        return ans;
    }
}

class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}