# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generate(self, left, right):
        if left == right:
            return [TreeNode(left,None,None)]
        if left> right:
            return [None]
        if right == 0:
            return [None]
        lis = []
        for i in range(left,right+1):
            lTree = self.generate(left,i-1)
            rTree = self.generate(i+1, right)
            for l in lTree:
                for r in rTree:
                    n = TreeNode(i,l,r)
                    lis.append(n)
        return lis
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.generate(1,n)
        