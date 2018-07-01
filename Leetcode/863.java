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
    private int[][] graph = new int[501][501];
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) 
    {
        buildGraph(root);
        boolean[] visited = new boolean[501];
        
        int last = target.val;
        visited[target.val] = true;
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(target.val);
        
        List<Integer> result = new ArrayList<>();
        
        while(!queue.isEmpty() && K >= 0)
        {
            int val = queue.pollFirst();
            if(K == 0)
                result.add(val);
            for(int adj = 0; adj < 501; adj++)
            {
                if(graph[val][adj] != 0 && !visited[adj])
                {
                    visited[adj] = true;
                    queue.add(adj);
                }
            }
            
            if(last == val)
            {
                K--;
                if(!queue.isEmpty())
                    last = queue.peekLast();
            }
        }
        
        return result;
    }
    
    private void buildGraph(TreeNode root)
    {
        if(root == null)
            return;
        
        if(root.left != null)
            graph[root.val][root.left.val] = 
                graph[root.left.val][root.val] = 1;
        if(root.right != null)
            graph[root.val][root.right.val] = 
                graph[root.right.val][root.val] = 1;
        
        buildGraph(root.left);
        buildGraph(root.right);
    }
    
}