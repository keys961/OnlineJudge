class Solution
{
    class People
    {
        int height;
        int numPeople;
        People(int h, int n)
        {
            this.height = h;
            this.numPeople = n;
        }
    }

    public int[][] reconstructQueue(int[][] people)
    {
        int[][] res = new int[people.length][2];
        List<People> list = new ArrayList<>();
        ArrayList<People> resList = new ArrayList<>(); //Do not use linked list

//        for(int i = 0; i < people.length; i++)
//            list.add(new People(people[i][0], people[i][1]));
//
//        Collections.sort(list, ((o1, o2) ->
//        {
//            if(o1.height == o2.height)
//                return o1.numPeople - o2.numPeople;
//            return o2.height - o1.height;
//        }));
        
        Arrays.sort(people, (o1, o2)->  //Sort with height desc first then numOfPeople asc
        {
            if(o1[0] == o2[0])
                return o1[1] - o2[1];
            return o2[0] - o1[0];
        });

        for(int[] p : people)
        {
            if(resList.size() == 0)
                resList.add(new People(p[0], p[1]));
            else
            {
                int cnt = p[1];
                int i = 0;
                while(cnt > 0) //Insert, like insert sort process
                {
                    for(i = 0; cnt > 0 && i < resList.size(); i++)
                    {
                        if(resList.get(i).height >= p[0])
                            cnt--;
                    }
                }
                resList.add(i, new People(p[0], p[1]));
            }
        }

        for(int i = 0; i < resList.size(); i++)
        {
            res[i][0] = resList.get(i).height;
            res[i][1] = resList.get(i).numPeople;
        }

        return res;
    }


}