class Solution
{
    public boolean canVisitAllRooms(List<List<Integer>> rooms) 
    {
        boolean[] visited = new boolean[rooms.size()];
        visited[0] = true;
        int count = 1;
        
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(0);
        
        while(!queue.isEmpty())
        {
            int room = queue.poll();
            for(int i = 0; i < rooms.get(room).size(); i++)
            {
                if(!visited[rooms.get(room).get(i)])
                {
                    visited[rooms.get(room).get(i)] = true;
                    count++;
                    queue.add(rooms.get(room).get(i));
                }
            }
        }
        
        return count == rooms.size();
    }
}