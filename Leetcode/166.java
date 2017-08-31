import java.util.*;

public class Solution
{
    public String fractionToDecimal(int numerator, int denominator)
    {
        if(numerator == 0)
            return "0";
        String integer = "";
        if(numerator < 0 ^ denominator < 0)
            integer += '-';
        numerator = Math.abs(numerator);
        denominator = Math.abs(denominator);
        integer += Integer.toString(numerator / denominator);
        if(numerator % denominator == 0)
            return integer;
        StringBuilder stringBuilder = new StringBuilder();
        numerator = numerator % denominator;

        HashMap<Integer, Integer> map = new HashMap<>();

        for(int r = numerator; r != 0; r %= denominator)
        {
            if(map.containsKey(r))
            {
                stringBuilder.insert(map.get(r), "(");
                stringBuilder.append(")");
                break;
            }
            map.put(r, stringBuilder.length());
            r *= 10;
            stringBuilder.append(r / denominator);
        }

        return integer + '.' + stringBuilder.toString();
    }

}