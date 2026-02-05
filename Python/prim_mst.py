"""
Prim's Algorithm - Minimum Spanning Tree
Problem: Find MST for college campus graph using adjacency matrix
Time Complexity: O(V²) where V is number of vertices
"""

import sys

V = 5  # Number of vertices

# Adjacency matrix representation of graph
# Rows/Cols: 0=CS, 1=AI, 2=Civil, 3=Mech, 4=Admin
G = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

def minKey(key, mstSet):
    """Find vertex with minimum key value from vertices not in MST"""
    m = sys.maxsize
    min_index = -1
    
    for v in range(V):
        if key[v] < m and not mstSet[v]:
            m = key[v]
            min_index = v
    
    return min_index

def primMST():
    """Prim's MST algorithm"""
    # Key values to pick minimum weight edge
    key = [sys.maxsize] * V
    parent = [None] * V  # Store MST
    key[0] = 0  # Start from vertex 0
    mstSet = [False] * V  # Track vertices in MST
    parent[0] = -1  # First node is root
    
    for _ in range(V - 1):
        # Pick minimum key vertex not in MST
        u = minKey(key, mstSet)
        mstSet[u] = True
        
        # Update key values of adjacent vertices
        for v in range(V):
            # Update if: edge exists, v not in MST, weight < current key
            if G[u][v] and not mstSet[v] and G[u][v] < key[v]:
                key[v] = G[u][v]
                parent[v] = u
    
    # Display MST
    print("Edge\t\tWeight")
    total_weight = 0
    for i in range(1, V):
        print(f"{parent[i]} - {i}\t\t{G[i][parent[i]]}")
        total_weight += G[i][parent[i]]
    print(f"\nTotal Weight: {total_weight}")

# Driver code
if __name__ == "__main__":
    print("Departments:")
    print("0 = CS, 1 = AI, 2 = Civil, 3 = Mech, 4 = Admin\n")
    print("Minimum Spanning Tree (Prim's Algorithm):\n")
    primMST()
