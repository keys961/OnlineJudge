class Solution 
{
    public int scoreOfParentheses(String S)
    {
        // We just count the deepest one..
        int score = 0;
        int time = 0;
        for(int i = 0; i < S.length(); i++)
        {
            char c = S.charAt(i);
            if(c == '(') 
                time++;
            else
            {
                time--;
                if(S.charAt(i - 1) == '(')
                    score += 1 << time;
            }
        }
        
        return score;
    }
}