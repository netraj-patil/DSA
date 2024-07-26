# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        i = 1
        temp1 = head
        temp2 = head
        while i<=n :
            i+= 1
            temp1 = temp1.next
        
        if temp1 is None:
            return head.next
        
        while temp1.next is not None:
            temp1 = temp1.next
            temp2 = temp2.next
        temp2.next = temp2.next.next
        
        return head
        
            
        