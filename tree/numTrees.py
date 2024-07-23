'''
Given an integer n, return the number of structurally unique BST's (binary search trees)
which has exactly n nodes of unique values from 1 to n.
'''

class Solution:
    def numTrees(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        s = 2*self.numTrees(n-1)
        for i in range(2,n):
            s += self.numTrees(i-1) * self.numTrees(n-i)
        return s