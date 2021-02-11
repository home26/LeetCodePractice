"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def __init__(self):
        self.visited = {}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        
        if node in self.visited:
            return self.visited[node]
        
        cloneNew = Node(node.val, [])
        
        self.visited[node] = cloneNew
        
        if node.neighbors:
            cloneNew.neighbors = [self.cloneGraph(n) for n in node.neighbors]
            
        return cloneNew
