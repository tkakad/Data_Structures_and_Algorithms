#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
    Node *front, *rear;

    Queue(){
        front = rear = NULL;
    }

    bool isEmpty(){
        return front == NULL && rear == NULL;
    }

    bool isFull(){
        Node *t = new Node;

        cout << "\nt == NULL: " << (t == NULL) << endl;

        if(t == NULL)
            return true;
        
        delete t;
        return false;
    }

    void enqueue(int x){
        if(isFull())
            cout << "Queue Overflow... No more space available in the heap!" << endl;
        else{
            Node *t = new Node;
            
            t->data = x;
            t->next = NULL;
            
            if(isEmpty())
                front = t;
            else
                rear->next = t;
            
            rear = t;
        }
    }

    int dequeue(){
        int x = -1;

        if(isEmpty())
            return x;
        
        Node *t = front;
        
        x = t->data;
        front = front->next;
        delete t;

        return x;
    }

    void display(){
        Node *t = front;

        cout << "\nQueue: ";

        while(t){
            cout << t->data << " ";
            t = t->next;
        }

        cout << endl;
    }

    int peek(int pos){
        if(isEmpty())
            return -1;

        Node *t = front;

        for(int i = 0; i < pos; i++){
            if(t->next == NULL)
                return -1;
            t = t->next;
        }

        return t->data;
    }
};

int main(){
    Queue Q;
    int index, temp;

    cout << "\n--------- Operation 1 ---------\n" << endl;

    cout << "Element to be pushed: " << 1 << endl;
    Q.enqueue(1);
    Q.display();

    cout << "\n--------- Operation 2 ---------\n" << endl;

    cout << "Element to be pushed: " << 2 << endl;
    Q.enqueue(2);
    Q.display();

    cout << "\n--------- Operation 3 ---------\n" << endl;

    cout << "Element to be pushed: " << 3 << endl;
    Q.enqueue(3);
    Q.display();

    cout << "\n--------- Operation 4 ---------\n" << endl;

    cout << "Element to be pushed: " << 4 << endl;
    Q.enqueue(4);
    Q.display();

    cout << "\n--------- Operation 5 ---------\n" << endl;

    cout << "Popped element: " << Q.dequeue() << endl;
    Q.display();

    cout << "\n--------- Operation 6 ---------\n" << endl;

    cout << "Enter the position index to peek at: ";
    cin >> index;
    cout << endl;

    temp = Q.peek(index);

    if(temp == -1)
        cout << "Invalid index!" << endl;
    else
        cout << "The element at position " << index << " is " << temp << endl;
    
    Q.display();

    cout << "\n--------- Operation 7 ---------\n" << endl;

    cout << "Enter the position index to peek at: ";
    cin >> index;
    cout << endl;
    
    temp = Q.peek(index);

    if(temp == -1)
        cout << "Invalid index!" << endl;
    else
        cout << "The element at position " << index << " is " << temp << endl;
    
    Q.display();

    cout << "\n--------- Operation 8 ---------\n" << endl;

    cout << "Enter the position index to peek at: ";
    cin >> index;
    cout << endl;
    
    temp = Q.peek(index);

    if(temp == -1)
        cout << "Invalid index!" << endl;
    else
        cout << "The element at position " << index << " is " << temp << endl;

    Q.display();
    
    return 0;
}