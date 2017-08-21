import java.util.*;

public class Solution
{
    public String simplifyPath(String path)
    {
        String[] directories = path.split("[/]+");
        Stack<String> stack = new Stack<>();
        for(int i = 0; i < directories.length; i++)
        {
            if(directories[i].equals(".") || directories[i].equals(""))
                continue;
            if(directories[i].equals(".."))
            {
                if (!stack.isEmpty())
                    stack.pop();
            }
            else
                stack.push(directories[i]);
        }
        StringBuilder stringBuilder = new StringBuilder();
        if(stack.isEmpty())
            return "/";

        List<String> list = stack.subList(0, stack.size());
        for(String item : list)
            stringBuilder.append("/" + item);
        return stringBuilder.toString();
    }
}