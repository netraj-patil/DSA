class MyStack:

    def __init__(self):
        self.s = []
        self.q = []
        

    def push(self, x: int) -> None:
        self.s.append(x)
        del(self.q)
        self.q=[]
        for no in self.s:
            self.q.insert(0,no)

    def pop(self) -> int:
        if self.empty():
            return -1
        n = self.top()
        del self.q[0]
        del self.s
        self.s=[]
        for no in self.q:
            self.s.insert(0,no)
        return n
        
    def top(self) -> int:
        if self.empty():
            return -1
        return self.q[0]

    def empty(self) -> bool:
        if len(self.q) == 0:
            return True
        return False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()