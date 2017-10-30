class Solution
{
    private int minCost = Integer.MAX_VALUE;

    private boolean isCheaper(List<Integer> price, List<Integer> special)
    {
        int normalPrice = 0;
        for(int i = 0; i < special.size() - 1; i++)
            normalPrice += special.get(i) * price.get(i);
        return normalPrice > special.get(special.size() - 1);
    }

    private boolean isValid(List<Integer> special, List<Integer> need)
    {
        for(int i = 0; i < need.size(); i++)
        {
            if(special.get(i) > need.get(i))
                return false;
        }
        return true;
    }

    private void listMinus(List<Integer> special, List<Integer> need)
    {
        for(int i = 0; i < need.size(); i++)
            need.set(i, need.get(i) - special.get(i));
    }

    private void listAdd(List<Integer> special, List<Integer> need)
    {
        for(int i = 0; i < need.size(); i++)
            need.set(i, need.get(i) + special.get(i));
    }

    private void helper(List<Integer> price, List<List<Integer>> special, List<Integer> needs, int index, int cost)
    {
        boolean canGetSpecial = false;

        for(int i = index; i < special.size(); i++)
        {
            if(isValid(special.get(i), needs))
            {
                canGetSpecial = true;
                listMinus(special.get(i), needs);
                int incCost = special.get(i).get(special.get(i).size() - 1);
                helper(price, special, needs, i, cost + incCost);
                listAdd(special.get(i), needs);
            }
        }

        if(!canGetSpecial)
        {
            int tempCost = cost;
            for(int i = 0; i < price.size(); i++)
                tempCost += price.get(i) * needs.get(i);

            if(tempCost < minCost)
                minCost = tempCost;
        }
    }

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs)
    {
        //Filter
        ListIterator<List<Integer>> iterator = special.listIterator();

        while(iterator.hasNext()) //use iterator to avoid java.util.ConcurrentModificationException
        {
            List<Integer> list = iterator.next();
            if (isCheaper(price, list))
                continue;
            iterator.remove();
        }

        helper(price, special, needs, 0, 0);

        return minCost;
    }
}