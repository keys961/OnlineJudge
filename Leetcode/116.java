import java.util.*;

public class Solution
{
    public void connect(TreeLinkNode root)
    {
        if(root == null)
            return;

        Queue<TreeLinkNode> queue = new LinkedList<>();
        queue.add(root);
        TreeLinkNode tail = root, lastNode = root;

        TreeLinkNode preNode = new TreeLinkNode(0);
        TreeLinkNode currentNode;

        while(!queue.isEmpty())
        {
            currentNode = queue.poll();
            preNode.next = currentNode;//Link
            preNode = currentNode;
            if(currentNode.left != null)
            {
                queue.add(currentNode.left);
                tail = currentNode.left;
            }
            if(currentNode.right != null)
            {
                queue.add(currentNode.right);
                tail = currentNode.right;
            }
            if(currentNode == lastNode)
            {
                preNode = new TreeLinkNode(0);
                lastNode = tail;
            }
        }
    }
}