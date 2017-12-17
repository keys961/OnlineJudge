class Solution
{
    public String shortestCompletingWord(String licensePlate, String[] words)
    {
        String minWords = null;
        licensePlate = licensePlate.toLowerCase();
        HashMap<Character, Integer> map = new HashMap<>();
        
        for(int i = 0; i < licensePlate.length(); i++) 
        {
            if (licensePlate.charAt(i) >= 'a' && licensePlate.charAt(i) <= 'z') 
            {
                if (map.containsKey(licensePlate.charAt(i)))
                    map.put(licensePlate.charAt(i),
                            map.get(licensePlate.charAt(i)) + 1);
                else
                    map.put(licensePlate.charAt(i), 1);
            }
        }
        
        for(String word : words)
        {
            boolean status = true;
            HashMap<Character, Integer> tmap = new HashMap<>(map);
            for(int i = 0; i < word.length(); i++)
            {
                if(tmap.containsKey(word.charAt(i)))
                    tmap.put(word.charAt(i), tmap.get(word.charAt(i)) - 1);
                
            }
            for(Character c : tmap.keySet()) 
            {
                if (tmap.get(c) > 0) 
                {
                    status = false;
                    break;
                }
            }
            if(!status)
                continue;
            
            if (minWords == null || minWords.length() > word.length())
                minWords = word;
        }
        
        return minWords;
    }
}