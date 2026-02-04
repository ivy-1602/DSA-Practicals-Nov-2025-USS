"""
Binary Search Tree - Complete Implementation
Operations: Insert, Delete, Search, Traversal, Depth, Mirror, Copy, Parents, Leaves, Level-wise
Time Complexity: O(log n) average, O(n) worst case
"""

class Node:
    def __init__(self, d):
        self.d = d
        self.l = self.r = None

class BST:
    def insert(self, r, d):
        """Insert a node (handles duplicates by ignoring them)"""
        if not r:
            return Node(d)
        if d < r.d:
            r.l = self.insert(r.l, d)
        elif d > r.d:
            r.r = self.insert(r.r, d)
        return r
    
    def search(self, r, d):
        """Search for a value in the tree"""
        if not r or r.d == d:
            return r
        return self.search(r.l, d) if d < r.d else self.search(r.r, d)
    
    def inorder(self, r):
        """Inorder traversal (Left-Root-Right)"""
        if r:
            self.inorder(r.l)
            print(r.d, end=' ')
            self.inorder(r.r)
    
    def depth(self, r):
        """Calculate depth/height of tree"""
        if not r:
            return 0
        return 1 + max(self.depth(r.l), self.depth(r.r))
    
    def mirror(self, r):
        """Create mirror image of tree"""
        if r:
            r.l, r.r = r.r, r.l
            self.mirror(r.l)
            self.mirror(r.r)
    
    def copy(self, r):
        """Create a deep copy of the tree"""
        if not r:
            return None
        n = Node(r.d)
        n.l = self.copy(r.l)
        n.r = self.copy(r.r)
        return n
    
    def parents(self, r):
        """Display all parent nodes with their children"""
        if r:
            if r.l or r.r:
                print(r.d, ":", end=' ')
                if r.l:
                    print(r.l.d, end=' ')
                if r.r:
                    print(r.r.d, end=' ')
                print()
            self.parents(r.l)
            self.parents(r.r)
    
    def leaves(self, r):
        """Display all leaf nodes"""
        if r:
            if not r.l and not r.r:
                print(r.d, end=' ')
            self.leaves(r.l)
            self.leaves(r.r)
    
    def level(self, r):
        """Level-wise traversal (BFS)"""
        if not r:
            return
        q = [r]
        while q:
            c = q.pop(0)
            print(c.d, end=' ')
            if c.l:
                q.append(c.l)
            if c.r:
                q.append(c.r)

# Driver code
if __name__ == "__main__":
    T = BST()
    R = None
    
    # Insert nodes
    for i in [50, 30, 70, 20, 40, 60, 80]:
        R = T.insert(R, i)
    
    print("Inorder Traversal:", end=' ')
    T.inorder(R)
    
    print("\nDepth of Tree:", T.depth(R))
    
    print("\nParent Nodes with Children:")
    T.parents(R)
    
    print("\nLeaf Nodes:", end=' ')
    T.leaves(R)
    
    print("\n\nLevel-wise Traversal:", end=' ')
    T.level(R)
    
    print("\n\nAfter Mirror:")
    T.mirror(R)
    T.inorder(R)
