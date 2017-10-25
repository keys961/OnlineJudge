class Solution
{
    public boolean isValidSerialization(String preorder)
    {
        String[] elements = preorder.split(","); // "#" is pop
        //Judge when popping, there is an exception or not
        Stack<String> stack = new Stack<>();

        for(int i = 0; i < elements.length - 1; i++)
        {
            String s = elements[i];
            if(s.equals("#"))
            {
                if(stack.isEmpty())
                    return false;
                stack.pop();
            }
            else
                stack.push(s);
        }
        if(elements.length == 1 && elements[0].equals("#"))
            return true;
        if(elements[elements.length - 1].equals("#") && elements[elements.length - 2].equals("#"))
            return true;
        return false;
    }
}