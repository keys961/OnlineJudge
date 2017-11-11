class Solution
{
  private int getConstant(String var)
    {
      if(var.length() == 0)
            return 0;
        int constant = 0;
        boolean flag = false;
        for(int i = 0; i < var.length() && var.charAt(i) != 'x'; i++)
        {
            flag = true;
            constant = constant * 10 + var.charAt(i) - '0';
        }
        if(!flag)
            return 1;
        return constant;
    }

    private int[] parseExpr(String expr)//0: coefficient, 1: constant
    {
        String[] vars = expr.split("[+\\-]");
        String[] operators = expr.split("[x0-9]");
        int[] res = new int[2];

        if(vars[0].contains("x"))
            res[0] += getConstant(vars[0]);
        else
            res[1] += getConstant(vars[0]);
        int i = 1;

        for(String op : operators)
        {
            if(op.length() == 0)
                continue;
            if (vars[i].contains("x"))
            {
                if (op.equals("+"))
                    res[0] += getConstant(vars[i++]);
                else
                    res[0] -= getConstant(vars[i++]);
            }
            else
            {
                if (op.equals("+"))
                    res[1] += getConstant(vars[i++]);
                else
                    res[1] -= getConstant(vars[i++]);
            }
        }

        return res;
    }

    public String solveEquation(String equation)
    {
        String[] exprs = equation.split("=");
        int[] params1 = parseExpr(exprs[0]);
        int[] params2 = parseExpr(exprs[1]);

        params1[0] -= params2[0];
        params1[1] -= params2[1];

        if(params1[0] == 0 && params1[1] != 0)
            return "No solution";
        if(params1[0] == 0)
            return "Infinite solutions";

        return "x=" + (-params1[1] / params1[0]);
    }
}