class Solution
{
    private int[] cost;

    private boolean[] visited;

    public int networkDelayTime(int[][] times, int N, int K)
    {
        cost = new int[N + 1];
        visited = new boolean[N + 1];

        Arrays.fill(cost, Integer.MAX_VALUE);
        Arrays.fill(visited, false);

        cost[K] = 0;

        while(true)
        {
            int minCost = Integer.MAX_VALUE;
            int minSpot = -1;
            for(int i = 1; i <= N; i++)
            {
                if(!visited[i])
                {
                    if(cost[i] < minCost)
                    {
                        minCost = cost[i];
                        minSpot = i;
                    }
                }
            }

            if(minSpot == -1)
                break;

            visited[minSpot] = true;

            for(int i = 0; i < times.length; i++)
            {
                if(times[i][0] == minSpot)
                {
                    if(!visited[times[i][1]])
                    {
                        if(cost[minSpot] + times[i][2] < cost[times[i][1]])
                            cost[times[i][1]] = cost[minSpot] + times[i][2];
                    }
                }
            }
        }
        int maxCost = -1;
        for(int i = 1; i <= N; i++)
            if(cost[i] > maxCost)
                maxCost = cost[i];

        if(maxCost == Integer.MAX_VALUE)
            return -1;
        return maxCost;
    }
}