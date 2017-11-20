class Solution
{
    private boolean isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i'
                || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U';
    }

    public String reverseVowels(String s)
    {
        List<Integer> vowelIndexList = new ArrayList<>();
        StringBuilder vowels = new StringBuilder();
        StringBuilder res = new StringBuilder(s);
        for(int i = 0; i < s.length(); i++)
        {
            if(isVowel(s.charAt(i)))
            {
                vowelIndexList.add(i);
                vowels.append(s.charAt(i));
            }
        }
        
        vowels.reverse();
        for(int i = 0; i < vowels.length(); i++)
        {
            int index = vowelIndexList.get(i);
            res.replace(index, index + 1, vowels.substring(i, i + 1));
        }
        
        return res.toString();
    }
}