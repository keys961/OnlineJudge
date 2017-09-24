class Solution {
 List<Integer> digits = new ArrayList<>();

    StringBuffer res = new StringBuffer();

    int timeDelta = Integer.MAX_VALUE;

    int currentTime = 0;

    private int calcDelta(List<Integer> time)
    {
        int val = (time.get(0) * 10 + time.get(1)) * 60 + (time.get(2) * 10 + time.get(3));
        int temp = val - currentTime;
        if(temp < 0)
            temp += 24 * 60;
        return temp;
    }

    private void dfs(List<Integer> time, int index)
    {
        if(time.size() == 4)
        {
            int delta = calcDelta(time);
            int hour = time.get(0) * 10 + time.get(1);
            int min = time.get(2) * 10 + time.get(3);
            if(hour > 24 || min >= 60)
                return;
            if(delta < timeDelta && delta != 0)
            {
                timeDelta = delta;
                res.delete(0, 4);
                for(int i = 0; i < 4; i++)
                    res.append(time.get(i));
            }
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            List<Integer> newList = new ArrayList<>(time);
            newList.add(digits.get(i));
            dfs(newList, i);
        }
    }

    public String nextClosestTime(String time)
    {
        String[] times = time.split("\\:");
        currentTime += Integer.parseInt(times[0]) * 60;
        currentTime += Integer.parseInt(times[1]);
        for(int i = 0; i < time.length(); i++)
        {
            if(time.charAt(i) != ':')
                digits.add(time.charAt(i) - '0');
        }
        dfs(new ArrayList<Integer>(), -1);
        if(res.length() == 0)
            return time;
        res.insert(2, ':');
        return res.toString();
    }
}