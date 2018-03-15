/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution 
{
    public int eraseOverlapIntervals(Interval[] intervals) 
    {
        Arrays.sort(intervals, (o1, o2)-> //greedy strategy : end min first.
                    {
                        if(o1.end == o2.end)
                            return o1.start - o2.start;
                        return o1.end - o2.end;
                    });        
        int count = 0;
        int ptr1 = 0, ptr2 = 1;
        for(; ptr2 < intervals.length; ptr2++)
        {
            if(isOverlapped(intervals[ptr1], intervals[ptr2]))
                count++;
            else
                ptr1 = ptr2;
        }
        
        return count;
    }
    
    private boolean isOverlapped(Interval a, Interval b)
    {
        if(a.start > b.start)
            return isOverlapped(b, a);
        
        if(a.end > b.start)
            return true;
        return false;
    }
}