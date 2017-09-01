public class Solution
{
    public String largestNumber(int[] nums)
    {
        List<Integer> list = new ArrayList<>();
        for(int num : nums)
            list.add(num);
        list.sort((o1, o2) ->
        {
            if(o1.equals(o2))
                return 0;
            String numA = Integer.toString(o1);
            String numB = Integer.toString(o2);

            String resA = numA + numB;
            String resB = numB + numA;

            return -resA.compareTo(resB);
        });

        StringBuilder stringBuilder = new StringBuilder();

        for(int num : list)
            stringBuilder.append(num);

        while(stringBuilder.charAt(0) == '0' && stringBuilder.length() > 1)
            stringBuilder.deleteCharAt(0);
        return stringBuilder.toString();
    }
}