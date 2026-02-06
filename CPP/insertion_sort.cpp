/*
 * Insertion Sort - Student Records
 * Problem: Sort student records by Name (Alphabetically) and CGPA (Descending)
 * Time Complexity: O(n²) worst case, O(n) best case
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
    
    // Insertion Sort by Name (Alphabetically)
    for(int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while(j >= 0 && s[j].name > key.name) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
    
    cout << "Sorted by Name:\n";
    for(int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].cgpa << endl;
    }
    
    // Insertion Sort by CGPA (Descending)
    for(int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while(j >= 0 && s[j].cgpa < key.cgpa) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
    
    cout << "\nSorted by CGPA (Desc):\n";
    for(int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].cgpa << endl;
    }
    
    return 0;
}
