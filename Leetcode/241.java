class Solution
{
    public List<Integer> diffWaysToCompute(String input) 
    {
        int num = 0;
        List<Integer> results = new LinkedList<>();
        for(int i = 0; i < input.length(); i++)
        {
            char c = input.charAt(i);
            if(c == '+' || c == '-' || c == '*') //divide & conquer, split 2 sub-expr then reassemble 2 list.
            {
                String expr1 = input.substring(0, i);
                String expr2 = input.substring(i + 1, input.length());
                
                List<Integer> values1 = diffWaysToCompute(expr1);
                List<Integer> values2 = diffWaysToCompute(expr2);
                
                for(int n1 : values1) //permulation & combination
                {
                    for(int n2 : values2)
                    {
                        switch(c)
                        {
                            case '+': results.add(n1 + n2); break;
                            case '-': results.add(n1 - n2); break;
                            case '*': results.add(n1 * n2); break;
                        }
                    }
                }
            }
            else
                num = num * 10 + c - '0';
        }
        
        if(results.size() == 0)
            results.add(num);
        return results;
    }
}