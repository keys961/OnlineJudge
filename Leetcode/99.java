class Solution 
{
    public void recoverTree(TreeNode root)
    {
        TreeNode mistake1 = root, mistake2 = root;
        int cnt = 0;

        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        TreeNode previous = null;
        // in-order iteration to find 2 mistakes
        while(!stack.empty() || node != null)  //cond 1: no empty or not null
        {
            while(node != null) //cond 2: not null
            {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            if(previous == null)
                previous = node;
            else if(cnt == 0)
            {
                if(node.val < previous.val)
                {
                    mistake1 = previous;
                    mistake2 = node;
                    cnt++;
                }
                previous = node;
            }
            else if(cnt == 1)
            {
                if (node.val < previous.val)
                {
                    mistake2 = node;
                    break;
                }
                previous = node;
            }
            node = node.right;
        }
        int temp = mistake1.val;
        mistake1.val = mistake2.val;
        mistake2.val = temp;
    }
}