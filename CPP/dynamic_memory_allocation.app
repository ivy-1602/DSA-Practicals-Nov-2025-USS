/*
 * Dynamic Memory Allocation - Student Details
 * Problem: Store student details using dynamically allocated memory
 * Demonstrates: new, delete operators for memory management
 */

#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char *name;
    float cgpa;
};

int main() {
    // Allocate memory for student
    Student *s = new Student;
    
    s->id = 1;
    
    // Allocate memory for name
    s->name = new char[strlen("Taylor Swift") + 1];
    strcpy(s->name, "Taylor Swift");
    
    s->cgpa = 9.5;
    
    // Display student details
    cout << "Student Details:\n";
    cout << "ID: " << s->id << endl;
    cout << "Name: " << s->name << endl;
    cout << "CGPA: " << s->cgpa << endl;
    
    // Free allocated memory
    delete[] s->name;
    delete s;
    
    cout << "\nMemory deallocated successfully!\n";
    
    return 0;
}
