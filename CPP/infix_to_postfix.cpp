/*
 * Stack ADT - Infix to Postfix Conversion
 * Problem: Convert infix expression to postfix using stack (linked list)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    
    void push(char x) {
        Node* t = new Node;
        t->data = x;
        t->next = top;
        top = t;
    }
    
    char pop() {
        if(!top) return '\0';
        char x = top->data;
        Node* t = top;
        top = top->next;
        delete t;
        return x;
    }
    
    char peek() {
        return top ? top->data : '\0';
    }
    
    bool empty() {
        return top == NULL;
    }
};

// Function to get precedence of operators
int prec(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

// Convert infix to postfix
string infixToPostfix(string in) {
    Stack st;
    string post = "";
    
    for(char c: in) {
        // If operand, add to output
        if(isalnum(c)) {
            post += c;
        }
        // If '(', push to stack
        else if(c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if(c == ')') {
            while(!st.empty() && st.peek() != '(') {
                post += st.pop();
            }
            st.pop(); // Remove '('
        }
        // If operator
        else {
            while(!st.empty() && prec(st.peek()) >= prec(c)) {
                post += st.pop();
            }
            st.push(c);
        }
    }
    
    // Pop remaining operators
    while(!st.empty()) {
        post += st.pop();
    }
    
    return post;
}

int main() {
    string in;
    cout << "Enter Infix Expression: ";
    cin >> in;
    cout << "Postfix Expression: " << infixToPostfix(in) << endl;
    return 0;
}
