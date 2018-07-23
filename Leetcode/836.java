class Solution 
{
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) 
    {
        int overlapX1 = Math.max(rec1[0], rec2[0]); // left - button of intersection
        int overlapY1 = Math.max(rec1[1], rec2[1]);
        
        int overlapX2 = Math.min(rec1[2], rec2[2]); // right - up of intersection
        int overlapY2 = Math.min(rec1[3], rec2[3]);
        
        return overlapX1 < overlapX2 && overlapY1 < overlapY2;
    }
}