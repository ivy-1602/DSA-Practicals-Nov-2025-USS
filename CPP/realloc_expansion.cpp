/*
 * Dynamic Array Expansion using realloc()
 * Problem: Expand student list as new entries are added
 * Demonstrates: Memory reallocation for growing arrays
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
    
    // Add first student
    n = 1;
    s = (Student*)realloc(s, n * sizeof(Student));
    s[0].id = 1;
    strcpy(s[0].name, "Taylor Swift");
    s[0].cgpa = 9.5;
    
    // Add second student
    n = 2;
    s = (Student*)realloc(s, n * sizeof(Student));
    s[1].id = 2;
    strcpy(s[1].name, "Tony Stark");
    s[1].cgpa = 9.4;
    
    // Add third student
    n = 3;
    s = (Student*)realloc(s, n * sizeof(Student));
    s[2].id = 3;
    strcpy(s[2].name, "Lightning McQueen");
    s[2].cgpa = 9.1;
    
    // Display all students
    cout << "Student Records:\n";
    cout << "================\n";
    for(int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "ID: " << s[i].id << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "CGPA: " << s[i].cgpa << endl;
    }
    
    // Free memory
    free(s);
    
    return 0;
}
