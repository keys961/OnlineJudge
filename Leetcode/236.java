class Solution
{
        private List<TreeNode> path = new ArrayList<>();

        private void getPath(TreeNode node, TreeNode target, List<TreeNode> path)
        {
            if(node == target)
            {
                this.path = new ArrayList<>(path);
                return;
            }

            if(node == null)
                return;
            
            if(node.left != null)
            {
                path.add(node.left);
                getPath(node.left, target, path);
                path.remove(path.size() - 1);
            }
            
            if(node.right != null)
            {
                path.add(node.right);
                getPath(node.right, target, path);
                path.remove(path.size() - 1);
            }
        }

        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
        {
            TreeNode res = root;
            List<TreeNode> pathP;
            List<TreeNode> pathQ;
            List<TreeNode> tempList = new ArrayList<>();
            tempList.add(root);
            getPath(root, p, tempList);
            pathP = path;
            getPath(root, q, tempList);
            pathQ = path;

            int len = Math.min(pathP.size(), pathQ.size());

            for(int i = 0; i < len; i++)
            {
                if(pathP.get(i) == pathQ.get(i))
                    res = pathP.get(i);
            }

            return res;
        }
}