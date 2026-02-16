# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        H = T = None
        carry = 0

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            total = v1 + v2 + carry
            carry = total // 10
            d = total % 10

            temp = ListNode(d)

            if H is None:
                H = T = temp
            else:
                T.next = temp
                T = temp

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return H

        