class Solution 
{
    private List<List<Integer>> paths = new ArrayList<>();
    
    //graph[node] = ajancent nodes of node..
    private void dfs(int[][] graph, int node, List<Integer> path)
    {
        int target = graph.length - 1;
        if(node == target)
        {
            paths.add(new ArrayList<>(path));
            return;
        }
        
        int[] ajancentNodes = graph[node];
        for(int n : ajancentNodes)
        {
            path.add(n);
            dfs(graph, n, path);
            path.remove(path.size() - 1);
        }
    }
    
    public List<List<Integer>> allPathsSourceTarget(int[][] graph)
    {
        if(graph.length == 0)
            return paths;
        
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(graph, 0, path);
        return paths;
    }
}