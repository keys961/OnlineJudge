class Solution 
{
    public String licenseKeyFormatting(String S, int K)
    {
        StringBuilder res = new StringBuilder();

        String[] segments = S.split("-");

        for(String segment : segments)
            res.append(segment);

        int totalLength = res.length();
        int firstLength = totalLength % K;
        int index = 0;
        if(firstLength != 0)
            index = firstLength;
        else
            index = K;

        while(index < res.length())
        {
            res.insert(index, '-');
            index += K + 1;
        }

        return res.toString().toUpperCase();
    }
}