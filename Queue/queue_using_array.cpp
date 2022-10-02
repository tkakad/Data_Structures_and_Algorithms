#include <iostream>

using namespace std;

struct Queue{
    int size, front, rear, *q;

    Queue(){
        cout << "Enter the size of the array: ";
        cin >> size;

        front = rear = -1;
        q = new int[size];
    }

    void display(){
        cout << "\nfront: " << front << "\trear: " << rear << endl;
        cout << "\nQueue: ";
        
        for(int i = 0; i < rear - front; i++) 
            cout << q[i] << " ";
        
        cout << endl;
    }

    bool isEmpty(){
        return front == rear;
    }

    bool isFull(){
        return rear - front == size;
    }

    void enqueue(int x){
        if(isFull())
            cout << "Queue Overflow!\n" << endl;
        else
            q[++rear] = x;
            cout << "q[rear]: " << q[rear] << endl;

    }

    int dequeue(){
        int x = -1;
        
        if(isEmpty())
            cout << "Queue Underflow!" << endl;
        else{
            x = q[rear];

            for(int i = 0; i < front - rear - 1; i++)
                q[i] = q[i+1];
            
            rear--;
        }

        return x;
    }

    int peek(int pos){
        if(pos < 0 || pos > rear){
            cout << "\nInvalid position!" << endl;
            return -1;
        }

        return q[rear];
    }

    int first_element(){
        return q[front + 1];
    }

    int last_element(){
        return q[rear];
    }
};

int main(){
    Queue Q;
    int index, result;

    Q.display();

    cout << "\n--------- Operation 1 ---------\n" << endl;

    Q.enqueue(1);
    Q.display();

    cout << "\n--------- Operation 2 ---------\n" << endl;

    Q.enqueue(2);
    Q.display();

    cout << "\n--------- Operation 3 ---------\n" << endl;

    Q.enqueue(3);
    Q.display();

    cout << "\n--------- Operation 4 ---------\n" << endl;

    Q.enqueue(4);
    Q.display();

    cout << "\n--------- Operation 5 ---------\n" << endl;

    cout << "Popped element: " << Q.dequeue() << endl;
    Q.display();

    cout << "\n--------- Operation 6 ---------\n" << endl;

    cout << "Popped element: " << Q.dequeue() << endl;
    Q.display();

    cout << "\n--------- Operation 7 ---------\n" << endl;

    cout << "Popped element: " << Q.dequeue() << endl;
    Q.display();

    cout << "\n--------- Operation 8 ---------\n" << endl;

    cout << "Popped element: " << Q.dequeue() << endl;
    Q.display();

    cout << "\n--------- Operation 9 ---------\n" << endl;

    cout << "Enter Queue index for peek: ";
    cin >> index;
    result = Q.peek(index);
    if(result != -1)
        cout << "\nElement at index " << index << " in the queue is " << result << endl;
    Q.display();

    return 0;
}