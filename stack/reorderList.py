# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        lis1 = []
        temp = head
        while temp is not None:
            lis1.append(temp)
            temp = temp.next
        temp = head
        for node in lis1:
            temp.next = node
            temp = temp.next
            if not lis1:
                break
            temp.next = lis1.pop()
            temp = temp.next
        temp.next = None