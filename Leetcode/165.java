public class Solution
{
    private int getLength(String[] ver)
    {
        for(int i = ver.length - 1; i > 0; i--)
        {
            if(Integer.parseInt(ver[i]) != 0)
                return i + 1;
        }
        return 1;
    }

    public int compareVersion(String version1, String version2)
    {
        String[] ver1 = version1.split("[.]{1}");
        String[] ver2 = version2.split("[.]{1}");
        int length1 = getLength(ver1);
        int length2 = getLength(ver2);

        int length = Math.min(length1, length2);

        for(int i = 0; i < length; i++)
        {
            int a = Integer.parseInt(ver1[i]);
            int b = Integer.parseInt(ver2[i]);
            if(a < b)
                return -1;
            else if(a > b)
                return 1;
        }

        if(length1 == length2)
            return 0;
        return length1 > length2 ? 1 : -1;

    }
}