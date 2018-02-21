class Trie
{
    private class Node
    {
        char val;
        Node[] nextVal = new Node[26];
        boolean hasStr = false;
        public Node(char val){ this.val = val; }
    }

    private Node trie = new Node((char)0);

    /** Initialize your data structure here. */
    public Trie()
    {}

    /** Inserts a word into the trie. */
    public void insert(String word)
    {
        int len = word.length();
        Node trieNode = trie;
        for(int i = 0; i < len; i++)
        {
            Node nextNode = trieNode.nextVal[word.charAt(i) - 'a'];
            if(nextNode == null)
                trieNode.nextVal[word.charAt(i) - 'a'] = new Node(word.charAt(i));
            trieNode = trieNode.nextVal[word.charAt(i) - 'a'];
        }
        trieNode.hasStr = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word)
    {
        int len = word.length();
        Node trieNode = trie;
        for(int i = 0; i < len; i++)
        {
            Node nextNode = trieNode.nextVal[word.charAt(i) - 'a'];
            if(nextNode == null)
                return false;
            trieNode = trieNode.nextVal[word.charAt(i) - 'a'];
        }
        return trieNode.hasStr;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix)
    {
        int len = prefix.length();
        Node trieNode = trie;
        for(int i = 0; i < len; i++)
        {
            if(trieNode.nextVal[prefix.charAt(i) - 'a'] == null)
                return false;
            trieNode = trieNode.nextVal[prefix.charAt(i) - 'a'];
        }
        return true;
    }
}