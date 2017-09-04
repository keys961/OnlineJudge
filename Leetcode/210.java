import java.util.*;

public class Solution
{
    public int[] findOrder(int numCourses, int[][] prerequisites)
    {
        int[] order = new int[numCourses];
        int p = 0;
        int[] inDegree = new int[numCourses];
        boolean[] visited = new boolean[numCourses];
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < prerequisites.length; i++)
            inDegree[prerequisites[i][0]]++;

        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
                queue.add(i);
        }

        while(!queue.isEmpty())
        {
            int temp = queue.poll();
            visited[temp] = true;
            order[p++] = temp;
            for(int i = 0; i < prerequisites.length; i++)
            {
                if(prerequisites[i][1] == temp)
                {
                    inDegree[prerequisites[i][0]]--;
                    if(inDegree[prerequisites[i][0]] == 0)
                        queue.add(prerequisites[i][0]);
                }
            }
        }

        for(int i = 0; i < numCourses; i++)
            if(!visited[i])
                return new int[0];
        return order;
    }
}