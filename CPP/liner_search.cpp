/*
 * Linear Search - Find Student by ID
 * Time Complexity: O(n)
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
    
    // Add students
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
    
    // Linear Search
    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;
    
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(s[i].id == searchID) {
            cout << "\nRecord Found!\n";
            cout << "ID: " << s[i].id << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "CGPA: " << s[i].cgpa << endl;
            found = true;
            break;
        }
    }
    
    if(!found) {
        cout << "Record Not Found\n";
    }
    
    free(s);
    return 0;
}
