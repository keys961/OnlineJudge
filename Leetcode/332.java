class Solution 
{
  private Map<String, PriorityQueue<String>> ticketMap = new TreeMap<>();

    private List<String> res = new ArrayList<>();

    private void dfs(String from)
    {
        while(ticketMap.containsKey(from) && !ticketMap.get(from).isEmpty())
            //reversely -  first add tail: No cycle at start point, Large lexical, SMALLER..
            dfs(ticketMap.get(from).poll());
        res.add(0, from);
    }

    public List<String> findItinerary(String[][] tickets)
    {
        for(String[] ticket : tickets)
        {
            if(!ticketMap.containsKey(ticket[0]))
                ticketMap.put(ticket[0], new PriorityQueue<>());
            PriorityQueue<String> set = ticketMap.get(ticket[0]);
            set.add(ticket[1]);
            ticketMap.put(ticket[0], set);
        }

        dfs("JFK");
        return res;
    }
}