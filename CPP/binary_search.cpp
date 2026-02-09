/*
 * Binary Search - Find Student by ID
 * Note: Array must be sorted by ID
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    int n = 0;
    Student* s = NULL;
    
    // Add students (sorted by ID)
    n = 1;
    s = (Student*)realloc(s, n * sizeof(Student));
    s[0].id = 1;
    strcpy(s[0].name, "Taylor Swift");
    s[0].cgpa = 9.5;
    
    n = 2;
    s = (Student*)realloc(s, n * sizeof(Student));
    s[1].id = 2;
    strcpy(s[1].name, "Tony Stark");
    s[1].cgpa = 9.4;
    
    n = 3;
    s = (Student*)realloc(s, n * sizeof(Student));
    s[2].id = 3;
    strcpy(s[2].name, "Lightning McQueen");
    s[2].cgpa = 9.1;
    
    // Binary Search
    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;
    
    int low = 0, high = n - 1, mid;
    bool found = false;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(s[mid].id == searchID) {
            cout << "\nRecord Found!\n";
            cout << "ID: " << s[mid].id << endl;
            cout << "Name: " << s[mid].name << endl;
            cout << "CGPA: " << s[mid].cgpa << endl;
            found = true;
            break;
        }
        else if(s[mid].id < searchID) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    if(!found) {
        cout << "Record Not Found\n";
    }
    
    free(s);
    return 0;
}
