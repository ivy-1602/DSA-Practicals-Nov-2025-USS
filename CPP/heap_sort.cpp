/*
 * Heap Sort Algorithm
 * Problem: Sort an array of integers in ascending order using max-heap
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

// Heapify a subtree rooted at node i
void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // If left child is larger than root
    if(left < n && a[left] > a[largest])
        largest = left;
    
    // If right child is larger than largest so far
    if(right < n && a[right] > a[largest])
        largest = right;
    
    // If largest is not root
    if(largest != i) {
        swap(a[i], a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(int a[], int n) {
    // Build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
    
    // Extract elements one by one from heap
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]); // Move current root to end
        heapify(a, i, 0);  // Heapify the reduced heap
    }
}

int main() {
    int a[] = {20, 5, 15, 10, 30};
    int n = 5;
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    heapSort(a, n);
    
    cout << "\nSorted array (Ascending): ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}
