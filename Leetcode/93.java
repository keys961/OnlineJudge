class Solution
{
    private List<String> res = new ArrayList<>();

    private String getIpAddr(List<Integer> addr)
    {
        StringBuilder s = new StringBuilder();
        for(int i = 0; i < addr.size() - 1; i++)
        {
            s.append(addr.get(i));
            s.append('.');
        }
        s.append(addr.get(addr.size() - 1));
        return s.toString();
    }

    private void helper(String ip, int index, List<Integer> addr)
    {
        if(addr.size() == 4)
        {
            if(index == ip.length())
            {
                String i = getIpAddr(addr);
                if(!res.contains(i))
                    res.add(i);
            }
            return;
        }

        for(int i = index; i < index + 3 && i < ip.length(); i++)
        {
            int temp = Integer.parseInt(ip.substring(index, i + 1));
            int cnt = i - index + 1;
            if(cnt == 2 && temp < 10 || cnt == 3 && temp < 100)
                continue;
            if(temp < 256)
            {
                addr.add(temp);
                helper(ip, i + 1, addr);
                addr.remove(addr.size() - 1);
            }
        }
    }

    public List<String> restoreIpAddresses(String s)
    {
        if(s.length() < 4 || s.length() > 12)
            return res;

        helper(s, 0, new ArrayList<Integer>());
        return res;
    }
}