class Solution
{
    public int[] constructRectangle(int area)
    {
        int upbound = (int)Math.sqrt(area);
        int w = 1;
        for(int i = 1; i <= upbound; i++)
            if(area % i == 0)
                w = i;
        return new int[]{area / w, w};
    }
}