public class Solution
{
    List<List<String>> res = new ArrayList<>();

    public class HashTable
    {
        public int[] table = new int[26];

        @Override
        public boolean equals(Object obj)
        {
            for(int i = 0; i < 26; i++)
                if(this.table[i] != ((HashTable) obj).table[i])
                    return false;
            return true;
        }

        @Override
        public int hashCode()
        {
            int code = 0;
            for(int i = 0; i < 26; i++)
                code = code * 26 + table[i];
            return code;
        }
    }

    private HashTable hash(String str)
    {
        HashTable t = new HashTable();
        for(int i = 0; i < str.length(); i++)
            t.table[str.charAt(i) - 'a'] += 1;
        return t;
    }

    public List<List<String>> groupAnagrams(String[] strs)
    {
        Map<HashTable, List<String>> map = new HashMap<>();

        for(String str : strs)
        {
            HashTable t = hash(str);
            if(map.containsKey(t))
            {
                List<String> temp = map.get(t);
                temp.add(str);
                map.put(t, temp);
            }
            else
            {
                List<String> temp = new ArrayList<>();
                temp.add(str);
                map.put(t, temp);
            }
        }

        Set<Map.Entry<HashTable, List<String>>> set = map.entrySet();
        for(Map.Entry<HashTable, List<String>> entry : set)
            res.add(entry.getValue());

        return res;

    }
}