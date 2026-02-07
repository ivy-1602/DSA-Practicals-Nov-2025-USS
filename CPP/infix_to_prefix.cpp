/*
 * Stack ADT - Infix to Prefix Conversion
 * Problem: Convert infix expression to prefix using stack (linked list)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top = NULL;
public:
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
        return !top;
    }
};

// Get precedence of operators
int prec(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

// Convert infix to prefix
string infixToPrefix(string in) {
    Stack st;
    string pre = "";
    
    // Step 1: Reverse the infix expression
    reverse(in.begin(), in.end());
    
    // Step 2: Swap '(' and ')'
    for(char &c: in) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
    
    // Step 3: Get postfix of modified expression
    for(char c: in) {
        if(isalnum(c)) {
            pre += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.peek() != '(') {
                pre += st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(st.peek()) > prec(c)) {
                pre += st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()) {
        pre += st.pop();
    }
    
    // Step 4: Reverse the result to get prefix
    reverse(pre.begin(), pre.end());
    
    return pre;
}

int main() {
    string in;
    cout << "Enter Infix Expression: ";
    cin >> in;
    cout << "Prefix Expression: " << infixToPrefix(in) << endl;
    return 0;
}
