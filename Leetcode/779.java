class Solution 
{
    public int kthGrammar(int N, int K)
    {
//         if(N == 1) TLE
//             return 0;
//         String s = "0";
//         for(int i = 2; i <= N; i++)
//         {
//             StringBuilder str = new StringBuilder();
//             for(int j = 0; j < s.length(); j++)
//             {
//                 switch(s.charAt(j))
//                 {
//                     case '0': str.append("01");
//                         break;
//                     case '1': str.append("10");
//                         break;
//                 }
//             }
//             s = str.toString();
//         }
        
//         return s.charAt(K - 1) - '0';
        if(N == 1)
            return 0;
        if(N == 2)
            return K - 1;
        
        int len = (int)(Math.pow(2, N - 1));
        if(K <= len / 2)
            return kthGrammar(N - 1, K);
        else if(K > len / 2 && K <= 3 * len / 4)
            return kthGrammar(N - 1, K - len / 4);
        else
            return kthGrammar(N - 1, K - len / 2) == 1 ? 0 : 1;
    }
}