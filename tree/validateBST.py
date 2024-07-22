# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]):
        if root is None:
            return []
        lis = []
        lis.extend(self.flatten(root.left))
        lis.append(root.val)
        lis.extend(self.flatten(root.right))
        return lis

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        lis = self.flatten(root)
        for i in range(len(lis)-1):
            if lis[i] >= lis[i+1]:
                return False
            
        return True