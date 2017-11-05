class Solution
{
    public boolean canConstruct(String ransomNote, String magazine) 
    {
        int[] table = new int[26];
        for(int i = 0; i < magazine.length(); i++)
            table[magazine.charAt(i) - 'a']++;
        for(int i = 0; i < ransomNote.length(); i++)
        {
            if(--table[ransomNote.charAt(i) - 'a'] < 0)
                return false;
        }
        return true;
    }
}