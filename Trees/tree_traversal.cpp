#include <iostream>

using namespace std;

struct Queue{
    int size, rear, *q;

    Queue(){
        cout << "\nEnter the required size of the queue: ";
        cin >> size;
        cout << endl;
        rear = -1;
        q = new int[size];
    }

    bool isEmpty(){
        return (rear == -1);
    }

    bool isFull(){
        return (rear == size - 1);
    }

    void enqueue(int x){
        if(isFull())
            cout << "\nQueue Overflow!" << endl;
        else
            q[++rear] = x;
    }

    int dequeue(){
        if(isEmpty())
            return -1;
        else{
            int x = q[0];

            for(int i = 0; i < rear; i++)
                q[i] = q[i+1];
            
            rear--;

            return x;
        }
    }

    void display(){
        cout << "\nQueue: ";

        for(int i = 0; i <= rear; i++)
            cout << q[i] << " ";
        
        cout << endl;
    }
};

int main(){
    Queue Q;

    return 0;
}