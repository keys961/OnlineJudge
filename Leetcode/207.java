import java.util.*;

class Solution
{
    public boolean canFinish(int numCourses, int[][] prerequisites)
    {
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
                return false;
        return true;
    }
}