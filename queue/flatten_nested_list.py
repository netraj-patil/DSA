# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        lis = []
        flag = False
        self.q = nestedList
        # self.q = []
        while not flag:
            lis = []
            flag = True
            for ele in self.q:
                if ele.isInteger():
                    lis.append(ele)
                else:
                    flag = False
                    lis.extend(ele.getList())
            self.q = lis
                    
    
    def next(self) -> int:
        no = self.q[0].getInteger()
        del self.q[0]
        return no
    
    def hasNext(self) -> bool:
        if not self.q:
            return False
        return True

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())