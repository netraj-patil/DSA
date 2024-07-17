'''
            1
          /   \
        2       5
       /  \       \
    3       4       6

convert this type of tree to :

1
  \
    2
      \
        3
          \
            4
              \
                5
                  \
                    6
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # temp = root.right
        temp2 = root
        if root is None:
            return
        if root.left is not None:
            self.flatten(root.left)
            if temp2.right is not None:
                temp2 = root.left
                while temp2.right is not None:
                    temp2 = temp2.right
                temp2.right = root.right
            
                self.flatten(root.right)
                root.right = root.left
                root.left = None
                return
            else:
                temp2.right = temp2.left
                temp2.left = None
                return
        if root.right is not None:
            self.flatten(root.right)
            return
        return
        