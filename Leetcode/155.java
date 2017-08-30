class MinStack {

    private List<Integer> minVal = new ArrayList<>();
    
    private Stack<Integer> stack;
    /** initialize your data structure here. */
    public MinStack() 
    {
        stack = new Stack<>();
    }
    
    public void push(int x) 
    {
        stack.push(x);
        if(minVal.size() == 0 || minVal.get(minVal.size() - 1) > x)
            minVal.add(x);
        else
            minVal.add(minVal.get(minVal.size() - 1));
    }
    
    public void pop() 
    {
        stack.pop();
        minVal.remove(minVal.size() - 1);
    }
    
    public int top() 
    {
        return stack.peek();    
    }
    
    public int getMin() 
    {
        return minVal.get(minVal.size() - 1);
    }
}