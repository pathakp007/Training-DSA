# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def solve(node):
            if node == p or node == q or node is None:
                return node
            l = solve(node.left)
            r = solve(node.right)
            if l and r:
                return node
            return l if l else r
        return solve(root)