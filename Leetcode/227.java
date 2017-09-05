import java.util.*;

public class Solution
{
    private int calculate(int left, int right, char operator)
    {
        switch (operator)
        {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/':
                if(right == 0)
                    return left;
                return left / right;
        }
        return left;
    }

    public int calculate(String s)
    {
        int low = 0, current = 0;
        Stack<Integer> values = new Stack<>();
        Stack<Character> operators = new Stack<>();

        int val = 0;
        for(; current < s.length(); current++)
        {
            char c = s.charAt(current);
            if(c >= '0' && c <= '9')
                val = val * 10 + c - '0';
            else
            {
                if(c == ' ')
                    continue;
                values.push(val);
                val = 0;
                if(c == '+' || c == '-')
                {
                    while(!operators.isEmpty())
                    {
                        int right = values.pop();
                        int left = values.pop();
                        char operator = operators.pop();
                        values.push(calculate(left, right, operator));
                    }
                    operators.push(c);
                }
                else
                {
                    if(!operators.isEmpty())
                    {
                        char temp = operators.peek();
                        if (temp == '*' || temp == '/')
                        {
                            temp = operators.pop();
                            int right = values.pop();
                            int left = values.pop();
                            values.push(calculate(left, right, temp));
                        }
                    }
                    operators.push(c);
                }
            }
        }
        //last
        values.push(val);
        while(!operators.isEmpty())
        {
            int right = values.pop();
            int left = values.pop();
            char operator = operators.pop();
            values.push(calculate(left, right, operator));
        }
        return values.peek();
    }
}