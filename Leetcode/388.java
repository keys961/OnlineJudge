class Solution
{
    public int lengthLongestPath(String input)
    {
        String[] nodes = input.split("\n");
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int maxLen = 0;
        for(String s : nodes)
        {
            int level = s.lastIndexOf("\t") + 1;
            while(level + 1 < stack.size())
                stack.pop();
            int len = stack.peek() + s.length() - level + 1;
            stack.push(len);
            if(s.contains("."))
            {
                if(len - 1 > maxLen)
                    maxLen = len - 1;
            }
        }
        return maxLen;
    }
}