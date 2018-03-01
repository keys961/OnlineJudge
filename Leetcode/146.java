class LRUCache
{
    private class Node
    {
        int key;
        int val;
        Node prev;
        Node next;
        Node(int key, int val)
        {
            this.key = key;
            this.val = val;
        }
    }

    private HashMap<Integer, Node> nodeMap = new HashMap<>();

    private Node head = null;

    private Node tail = null;


    public LRUCache(int capacity) //init linked list
    {
        head = new Node(0, 0);
        tail = head;

        for(int i = 1; i < capacity; i++)
        {
            Node temp = new Node(0, 0);
            temp.prev = tail;
            tail.next = temp;
            tail = temp;
        }
    }

    public int get(int key)
    {
        if(!nodeMap.containsKey(key))
            return -1;
        Node node = nodeMap.get(key);
        int value = node.val;
        putNodeToTail(node);//move to tail if accessed

        return value;
    }

    public void put(int key, int value)
    {
        Node node = null;
        int oldKey = -1;
        if(!nodeMap.containsKey(key))
        {
            node = head;
            oldKey = node.key;
        }
        else
        {
            node = nodeMap.get(key);
            oldKey = node.key;
        }
        node.key = key;
        node.val = value;

        putNodeToTail(node); //to tail
        nodeMap.remove(oldKey);//remove old key
        nodeMap.put(key, node);//add new key
    }

    private void putNodeToTail(Node node)
    {
        if(node == head)
        {
            if(head.next != null)
                head = head.next;
            head.prev = null;
            tail.next = node;
            node.prev = tail;
            tail = node;
        }
        else if(node != tail)
        {
            Node prev = node.prev;
            Node next = node.next;

            prev.next = next;
            next.prev = prev;

            tail.next = node;
            node.prev = tail;
            node.next = null;

            tail = node;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */