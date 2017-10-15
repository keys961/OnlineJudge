class Solution 
{
    private Map<Integer, Integer> map = new HashMap<>();

        private int getSubtreeSum(TreeNode node)
        {
            if(node == null)
                return 0;
            
            return node.val + getSubtreeSum(node.left) + getSubtreeSum(node.right);
        }
        
        private void traversal(TreeNode node)
        {
            if(node == null)
                return;
            
            int sum = getSubtreeSum(node);
            if(map.containsKey(sum))
                map.put(sum, map.get(sum) + 1);
            else
                map.put(sum, 1);
            traversal(node.left);
            traversal(node.right);
        }
        
        public int[] findFrequentTreeSum(TreeNode root) 
        {
            traversal(root);
            ArrayList<Integer> list = new ArrayList<>();
            int maxVal = 0;
            for(Integer i : map.keySet())
            {
                if(maxVal < map.get(i))
                {
                    maxVal = map.get(i);
                    list.clear();
                    list.add(i);
                }
                else if(maxVal == map.get(i))
                    list.add(i);
            }
            
            int[] res = new int[list.size()];
            for(int i = 0; i < res.length; i++)
                res[i] = list.get(i);
            return res;
        }
}