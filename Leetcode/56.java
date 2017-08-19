import java.util.*;

public class Solution
{
    public class Interval
    {
        int start;
        int end;
        Interval(){ start = end = 0; }
        Interval(int s, int e) { start = s; end = e; }
    }

    private boolean canMerge(Interval a, Interval b)
    {
        if(a.end < b.start || b.end < a.start)
            return false;
        return true;
    }


    public List<Interval> merge(List<Interval> intervals)
    {
        Collections.sort(intervals, (o1, o2) -> o1.start - o2.start);
        Stack<Interval> stack = new Stack<>();

        for(Interval interval : intervals)
        {
            if(stack.isEmpty())
                stack.push(interval);
            else
            {
                if(canMerge(stack.peek(), interval))
                {
                    Interval temp = stack.pop();
                    Interval newInterval = new Interval(Math.min(temp.start, interval.start),
                            Math.max(temp.end, interval.end));
                    stack.push(newInterval);
                }
                else
                    stack.push(interval);
            }
        }

        return stack.subList(0, stack.size());
    }
}