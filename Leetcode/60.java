import java.util.*;

public class Solution
{
//      Backtracking TLE!
//    private int k = 0;
//    private String res = null;
//
//    private void getOnePermutation(StringBuilder str, boolean[] visited , int n)
//    {
//        if(str.length() == n)
//        {
//            k--;
//            if(k == 0)
//                res = str.toString();
//            return;
//        }
//
//        if(res != null)
//            return;
//
//        for(int i = 1; i <= n; i++)
//        {
//            if(res != null)
//                return;
//            if(!visited[i])
//            {
//                visited[i] = true;
//                str.append(Integer.toString(i));
//                getOnePermutation(str, visited, n);
//                str.deleteCharAt(str.length() - 1);
//                visited[i] = false;
//            }
//        }
//    }

//    public String getPermutation(int n, int k)
//    {
//        this.k = k;
//        StringBuilder stringBuilder = new StringBuilder();
//        boolean[] visited = new boolean[10];
//        getOnePermutation(stringBuilder, visited, n);
//        return res;
//    }

    public String getPermutation(int n, int k)
    {
        List<Integer> list = new ArrayList<>();
        int[] factorials = new int[n];
        factorials[0] = 1;
        for(int i = 1; i < n; i++)
            factorials[i] = factorials[i - 1] * i;
        for(int i = 1; i <= n; i++)
            list.add(i);

        return getOnePermulation(list, k, factorials);
    }

    private String getOnePermulation(List<Integer> list, int k, int[] factorials)
    {
        if(list.size() == 0)
            return "";

        int num = (k - 1) / factorials[list.size() - 1];
        String str = Integer.toString(list.get(num));
        k -= num * factorials[list.size() - 1];
        list.remove(num);

        return str + getOnePermulation(list, k, factorials);
    }
}