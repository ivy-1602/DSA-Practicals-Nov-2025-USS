/*
 * Merge Sort - Online Orders by Delivery Time
 * Problem: Sort online orders by estimated delivery time (ascending)
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temp arrays
    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    
    // Merge the temp arrays back
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        
        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        
        // Merge the sorted halves
        merge(a, l, m, r);
    }
}

int main() {
    int time[] = {45, 10, 30, 60, 25};
    int n = 5;
    
    cout << "Delivery times (unsorted): ";
    for(int i = 0; i < n; i++)
        cout << time[i] << " ";
    
    mergeSort(time, 0, n - 1);
    
    cout << "\nSorted by delivery time (ascending): ";
    for(int i = 0; i < n; i++)
        cout << time[i] << " ";
    cout << endl;
    
    return 0;
}
