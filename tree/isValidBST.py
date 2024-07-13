# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root.left is None and root.right is None:
            return True
        if root.left is None:
            if root.val < root.right.val:
                return self.isValidBST(root.right) and True
            else:
                return False
        
        if root.right is None:
            if root.val > root.left.val:
                return self.isValidBST(root.left) and True
            else:
                return False
        
        if root.left.val < root.val and root.val < root.right.val:
            return self.isValidBST(root.left) and self.isValidBST(root.right) and True
        else:
            return False