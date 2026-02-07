/*
 * Circular Queue using Array
 * Operations: Enqueue, Dequeue, Display
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n)
 */

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
    
public:
    CircularQueue() {
        front = rear = -1;
    }
    
    void enqueue(int x) {
        if((rear + 1) % SIZE == front) {
            cout << "Queue is Full\n";
        }
        else {
            if(front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            cout << x << " inserted\n";
        }
    }
    
    void dequeue() {
        if(front == -1) {
            cout << "Queue is Empty\n";
        }
        else {
            cout << arr[front] << " deleted\n";
            if(front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
        }
    }
    
    void display() {
        if(front == -1) {
            cout << "Queue is Empty\n";
        }
        else {
            cout << "Queue: ";
            int i = front;
            while(true) {
                cout << arr[i] << " ";
                if(i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue q;
    int ch, val;
    
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        
        switch(ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(ch != 4);
    
    return 0;
}
