# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        a = ListNode(0)   # small list dummy
        b = ListNode(0)   # big list dummy
        
        p = a   # pointer for small list
        q = b   # pointer for big list
        
        while head:
            if head.val < x:
                p.next = head
                p = p.next
            else:
                q.next = head
                q = q.next
            head = head.next
        
        q.next = None        # stop cycle
        p.next = b.next      # join lists
        
        return a.next 
        
