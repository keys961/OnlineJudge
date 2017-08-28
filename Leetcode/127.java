import java.util.*;

public class Solution
{
    private boolean checkLadder(String a, String b)
    {
        int count = 0;
        for(int i = 0; i < a.length(); i++)
            if(a.charAt(i) != b.charAt(i))
                count++;
        return count == 1;
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList)
    {
        if(wordList.size() == 0)
            return 0;
        int index = -1;
        for(int i = 0; i < wordList.size(); i++)
            if(endWord.equals(wordList.get(i)))
                index = i;
        if(index == -1)
            return 0;

        boolean[] visited = new boolean[wordList.size()];
        int level = 0;
        String tail = beginWord, last = beginWord;
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);

        while(!queue.isEmpty())
        {
            String temp = queue.poll();
            if(temp.equals(endWord))
                break;
            for(int i = 0; i < wordList.size(); i++)
                if(!visited[i] && checkLadder(temp, wordList.get(i)))
                {
                    queue.add(wordList.get(i));
                    visited[i] = true;
                    tail = wordList.get(i);
                }

            if(temp.equals(last))
            {
                level++;
                last = tail;
            }
        }

        if(!visited[index])
            return 0;
        return ++level;
    }
}