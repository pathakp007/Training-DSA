from collections import deque

class MyStack:

    def __init__(self):
        self.d = deque()

    def push(self, x: int) -> None:
        self.d.append(x)

    def pop(self) -> int:
        return self.d.pop()

    def top(self) -> int:
        return self.d[-1]

    def empty(self) -> bool:
        return len(self.d) == 0


# Example usage:
# obj = MyStack()
# obj.push(10)
# obj.push(20)
# print(obj.top())    # 20
# print(obj.pop())    # 20
# print(obj.empty())  # False