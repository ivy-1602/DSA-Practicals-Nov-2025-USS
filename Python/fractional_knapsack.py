"""
Fractional Knapsack - Maximize Shipping Profit
Problem: Load truck with parcels to maximize profit (partial parcels allowed)
Algorithm: Greedy approach - sort by value/weight ratio
Time Complexity: O(n log n)
"""

def fractional_knapsack(wt, val, cap):
    """
    Solve fractional knapsack problem
    Args:
        wt: list of weights
        val: list of values
        cap: knapsack capacity
    Returns:
        maximum profit
    """
    # Calculate value/weight ratio for each item
    ratio = [(val[i]/wt[i], wt[i], val[i]) for i in range(len(wt))]
    
    # Sort by ratio in descending order (greedy choice)
    ratio.sort(reverse=True)
    
    profit = 0
    
    for r, w, v in ratio:
        if cap >= w:
            # Take full item
            profit += v
            cap -= w
        else:
            # Take fractional item
            profit += r * cap
            break
    
    return profit

# Driver code
if __name__ == "__main__":
    # Parcel details
    weights = [10, 20, 30]
    values = [60, 100, 120]
    capacity = 50
    
    print("Shipping Problem:")
    print("================")
    print(f"Truck Capacity: {capacity} kg\n")
    
    print("Available Parcels:")
    for i in range(len(weights)):
        ratio = values[i] / weights[i]
        print(f"  Parcel {i+1}: Weight={weights[i]}kg, "
              f"Value=${values[i]}, Ratio=${ratio:.2f}/kg")
    
    max_profit = fractional_knapsack(weights, values, capacity)
    
    print(f"\nMaximum Profit: ${max_profit}")
    print("\nStrategy: Load parcels with highest value/weight ratio first")
