/*
 * Selection Sort - Student Records
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
    
    // Selection Sort by Name (Alphabetically)
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(s[j].name < s[min].name) {
                min = j;
            }
        }
        swap(s[i], s[min]);
    }
    
    cout << "Sorted by Name:\n";
    for(int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].cgpa << endl;
    }
    
    // Selection Sort by CGPA (Descending)
    for(int i = 0; i < n - 1; i++) {
        int max = i;
        for(int j = i + 1; j < n; j++) {
            if(s[j].cgpa > s[max].cgpa) {
                max = j;
            }
        }
        swap(s[i], s[max]);
    }
    
    cout << "\nSorted by CGPA (Desc):\n";
    for(int i = 0; i < n; i++) {
        cout << s[i].name << " - " << s[i].cgpa << endl;
    }
    
    return 0;
}
