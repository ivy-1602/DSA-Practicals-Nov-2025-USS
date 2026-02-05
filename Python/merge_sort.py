"""
Merge Sort - Online Orders by Delivery Time
Problem: Sort orders by estimated delivery time for priority delivery
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

def merge_sort(arr):
    """Recursive merge sort algorithm"""
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]  # Left half
        R = arr[mid:]  # Right half
        
        # Recursively sort both halves
        merge_sort(L)
        merge_sort(R)
        
        # Merge sorted halves
        i = j = k = 0
        
        # Compare elements and merge
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        # Copy remaining elements from L
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        
        # Copy remaining elements from R
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

# Driver code
if __name__ == "__main__":
    # Delivery times in minutes
    orders = [45, 10, 30, 60, 25]
    
    print("Unsorted Delivery Times:", orders)
    
    merge_sort(orders)
    
    print("Sorted by Delivery Time (Ascending):", orders)
    print("\nPriority Order:")
    for i, time in enumerate(orders, 1):
        print(f"  {i}. Deliver in {time} minutes")
