#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;

    
    Node(int value) : data(value), next(nullptr) {}
};

class Cr_Queue {
public:
    Node* front;  
    Node* rear;   


    Cr_Queue() : front(nullptr), rear(nullptr) {}

    ~Cr_Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty()  {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } 
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            cout << "It is empty" << endl;
        }
    }

    void show()  {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
     Cr_Queue Q1;

    Q1.enqueue(4);
    Q1.enqueue(13);
    Q1.enqueue(25);
    Q1.enqueue(30);
    Q1.enqueue(43);
    Q1.enqueue(55);

    Q1.show() ;
    cout<< endl;


    Q1.dequeue();
    Q1.dequeue();
    Q1.dequeue();
    Q1.dequeue();
    Q1.show() ;



    return 0;
}