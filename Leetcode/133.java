import java.util.*;

public class Solution
{
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node)
    {
        if(node == null)
            return null;

        UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
        Map<Integer, UndirectedGraphNode> visited = new HashMap<>();
        visited.put(newNode.label, newNode);
        Queue<UndirectedGraphNode> queue = new LinkedList<>();
        queue.add(node);
        while(!queue.isEmpty())
        {
            UndirectedGraphNode temp = queue.poll();
            for(UndirectedGraphNode adjNode : temp.neighbors)
            {
                if(!visited.containsKey(adjNode.label))
                {
                    queue.add(adjNode);
                    visited.put(adjNode.label, new UndirectedGraphNode(adjNode.label));
                }
                visited.get(temp.label).neighbors.add(visited.get(adjNode.label));
            }
        }
        return newNode;
    }
}