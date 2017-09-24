class Solution
{
    public int calPoints(String[] ops)
    {
        List<Integer> list = new ArrayList<>();
        int sum = 0;
        for(String str : ops)
        {
            if(str.equals("+"))
            {
                if(list.size() >= 2)
                {
                    list.add(list.get(list.size() - 1) + list.get(list.size() - 2));
                    sum += list.get(list.size() - 1);
                }
            }
            else if(str.equals("D"))
            {
                if(list.size() >= 1)
                {
                    list.add(list.get(list.size() - 1) * 2);
                    sum += list.get(list.size() - 1) ;
                }
            }
            else if(str.equals("C"))
            {
                if(list.size() >= 1)
                {
                    sum -= list.get(list.size() - 1);
                    list.remove(list.size() - 1);
                }
            }
            else
            {
                int pts = Integer.parseInt(str);
                list.add(pts);
                sum += pts;
            }
        }
        return sum;

    }
}