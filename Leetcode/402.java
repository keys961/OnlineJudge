class Solution
{
   public String removeKdigits(String num, int k)
    {
        if(num.length() == k)
            return "0";

        Stack<Integer> stack = new Stack<>(); //using stack, just like convert mid-fix expr to prefix expr
        int i = 0;
        for(i = 0; i < num.length() && k > 0; i++)
        {
            if(stack.empty() || num.charAt(i) - '0' >= stack.peek())
                stack.push(num.charAt(i) - '0');
            else
            {
                while(!stack.empty() && k > 0 && stack.peek() > num.charAt(i) - '0')
                {
                    k--;
                    stack.pop();
                }
                stack.push(num.charAt(i) - '0');
            }
        }
        
        while(k > 0)
        {
            stack.pop();
            k--;
        }
        
        List<Integer> list = stack.subList(0, stack.size());
        StringBuilder stringBuilder = new StringBuilder();
        for(Integer integer : list)
            stringBuilder.append(integer);
        stringBuilder.append(num.substring(i));
        while(stringBuilder.charAt(0) == '0' && stringBuilder.length() > 1)
            stringBuilder.deleteCharAt(0);
        return stringBuilder.toString();
    }
}