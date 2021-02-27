class Solution:
    def splitBST(self, root: TreeNode, V: int) -> List[TreeNode]:
        if not root:
            return [None, None]
        if root.val == V:
            temp = root.right
            root.right = None
            return [root, temp]
        elif root.val > V:
            small, large = self.splitBST(root.left, V)
            root.left = large
            return [small, root]
        else:
            small, large = self.splitBST(root.right, V)
            root.right = small
            return [root, large]
