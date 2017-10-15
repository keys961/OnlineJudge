class Solution
{
    private Map<Integer, Integer> map = new HashMap<>();
        
        private void traversal(TreeNode node)
        {
            if(node == null)
                return;
            
            if(map.containsKey(node.val))
                map.put(node.val, map.get(node.val) + 1);
            else
                map.put(node.val, 1);
            
            traversal(node.left);
            traversal(node.right);
        }
        
        public int[] findMode(TreeNode root)
        {
            traversal(root);
            if(map.size() == 0)
                return new int[0];
            
            List<Integer> list = new ArrayList<>();
            int maxVal = 0;
            for (Integer integer : map.keySet())
            {
                if(map.get(integer) > maxVal)
                {
                    maxVal = map.get(integer);
                    list.clear();
                    list.add(integer);
                }
                else if(map.get(integer) == maxVal)
                    list.add(integer);
            }
            
            int[] res = new int[list.size()];
            for(int i = 0; i < res.length; i++)
                res[i] = list.get(i);
            return res;
        }
}