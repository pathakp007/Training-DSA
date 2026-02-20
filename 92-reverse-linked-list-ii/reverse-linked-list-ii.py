class Solution:
    def reverseBetween(self, head, left, right):

        if left == right:
            return head

        temp = head
        count = 0

        pend = None
        p2start = None
        p2end = None
        p3start = None

        # -------- Find split points --------
        while temp:
            if count == left - 2:
                pend = temp
                p2start = temp.next

            if count == right - 1:
                p2end = temp
                p3start = temp.next
                break

            temp = temp.next
            count += 1

        # If reversing from head
        if left == 1:
            p2start = head

        # -------- Cut middle part --------
        if pend:
            pend.next = None
        p2end.next = None

        # -------- Reverse middle part --------
        prev = None
        curr = p2start
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        # -------- Join parts --------
        if pend:
            pend.next = prev
        else:
            head = prev   # if left == 1

        p2start.next = p3start

        return head