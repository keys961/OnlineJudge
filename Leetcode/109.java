import java.util.*;

public class Solution
{
    private TreeNode insert(List<Integer> list, int low, int up)
    {
        if(low > up)
            return null;
        if(low == up)
            return new TreeNode(list.get(low));
        int mid = (low + up) / 2;
        TreeNode root = new TreeNode(list.get(mid));
        root.left = insert(list, low, mid - 1);
        root.right = insert(list, mid + 1, up);
        return root;
    }

    public TreeNode sortedListToBST(ListNode head)
    {
        List<Integer> list = new ArrayList<>();
        while(head != null)
        {
            list.add(head.val);
            head = head.next;
        }
        return insert(list, 0, list.size() - 1);
    }
}