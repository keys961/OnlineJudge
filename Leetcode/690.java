/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution 
{
    private int helper(Employee e, List<Employee> list)
    {
        int val = e.importance;
        if(e.subordinates.size() == 0)
            return val;
        for(int i : e.subordinates)
            val += helper(findEmployee(list, i), list);
        return val;
    }
    
    private Employee findEmployee(List<Employee> list, int id)
    {
        for(Employee e: list)
        {
            if(e.id == id)
                return e;
        }
        return null;
    }
    
    public int getImportance(List<Employee> employees, int id)
    {
        return helper(findEmployee(employees, id), employees);
    }
}