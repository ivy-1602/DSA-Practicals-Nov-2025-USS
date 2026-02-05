"""
Kruskal's Algorithm - Minimum Spanning Tree
Problem: Find MST for college campus graph (departments connected by distances)
Time Complexity: O(E log E) where E is number of edges
Uses Union-Find data structure
"""

class Graph:
    def __init__(self, v):
        self.V = v  # Number of vertices
        self.edges = []  # List of edges
    
    def add(self, u, v, w):
        """Add an edge with weight"""
        self.edges.append([u, v, w])
    
    def find(self, parent, i):
        """Find set of element i (with path compression)"""
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])
    
    def union(self, parent, rank, x, y):
        """Union of two sets (union by rank)"""
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        
        # Attach smaller rank tree under root of higher rank tree
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1
    
    def Kruskal(self):
        """Kruskal's MST algorithm"""
        # Sort edges by weight
        self.edges.sort(key=lambda x: x[2])
        
        parent = []
        rank = []
        res = []  # Store MST edges
        
        # Initialize parent and rank
        for n in range(self.V):
            parent.append(n)
            rank.append(0)
        
        e = 0  # Edge count in MST
        i = 0  # Index for sorted edges
        
        while e < self.V - 1:
            u, v, w = self.edges[i]
            i += 1
            
            x = self.find(parent, u)
            y = self.find(parent, v)
            
            # If including edge doesn't cause cycle
            if x != y:
                e += 1
                res.append([u, v, w])
                self.union(parent, rank, x, y)
        
        # Display MST
        print("Edges in Minimum Spanning Tree:")
        print("Edge\t\tWeight")
        total_weight = 0
        for u, v, w in res:
            print(f"{u} - {v}\t\t{w}")
            total_weight += w
        print(f"\nTotal Weight: {total_weight}")

# Driver code
if __name__ == "__main__":
    # Graph with 5 nodes (departments)
    g = Graph(5)
    
    # Adding edges (dept1, dept2, distance)
    g.add(0, 1, 2)  # CS - AI
    g.add(0, 2, 4)  # CS - Civil
    g.add(1, 2, 1)  # AI - Civil
    g.add(1, 3, 7)  # AI - Mech
    g.add(2, 3, 3)  # Civil - Mech
    g.add(3, 4, 5)  # Mech - Admin
    
    print("Departments:")
    print("0 = CS, 1 = AI, 2 = Civil, 3 = Mech, 4 = Admin\n")
    
    g.Kruskal()
