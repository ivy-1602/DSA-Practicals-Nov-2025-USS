/*
 * Bubble Sort - Student Records
 * Problem: Sort student records by Name (Alphabetically) and CGPA (Descending)
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    float cgpa;
};

int main() {
    Student s[3] = {
        {"Taylor Swift", 9.2},
        {"Lightning McQueen", 8.5},
        {"Tony Stark", 9.8}
    };
    int n = 3;
    
    // Sort by Name (Alphabetically)
    cout << "Sorting by Name..." << endl;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(s[j].name > s[j+1].name) {
                swap(s[j], s[j+1]);
            }
        }
    }
    
    cout << "Sorted by Name:\n";
    for(int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].cgpa << endl;
    }
    
    // Sort by CGPA (Descending)
    cout << "\nSorting by CGPA (Descending)..." << endl;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(s[j].cgpa < s[j+1].cgpa) {
                swap(s[j], s[j+1]);
            }
        }
    }
    
    cout << "Sorted by CGPA (Desc):\n";
    for(int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].cgpa << endl;
    }
    
    return 0;
}
