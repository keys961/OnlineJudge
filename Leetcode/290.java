class Solution
{
    public boolean wordPattern(String pattern, String str)
    {
        String[] words = str.split("\\s+");
        HashMap<String, Character> str2charMap = new HashMap<>();
        HashMap<Character, String> char2strMap = new HashMap<>();
        
        if(words.length != pattern.length())
            return false;
        
        for(int i = 0; i < pattern.length(); i++)
        {
            if(!str2charMap.containsKey(words[i]) && !char2strMap.containsKey(pattern.charAt(i)))
            {
                str2charMap.put(words[i], pattern.charAt(i));
                char2strMap.put(pattern.charAt(i), words[i]);
            }
            else
            {
                if(str2charMap.get(words[i]) != Character.valueOf(pattern.charAt(i)) || !char2strMap.get(pattern.charAt(i)).equals(words[i]))
                    return false;
            }
        }

        return true;
    }
}