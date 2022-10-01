#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *top = NULL;
};

void push(Node* st, int x){
    Node *t = new Node;

    if(t == NULL)
        cout << "Stack Overflow!" << endl;
    else{
        t->data = x;
        t->next = st->top;
        st->top = t;
    }
}

int pop(Node *st){
    int x = -1;

    if(st->top == NULL)
        cout << "Stack Underflow!" << endl;
    else{
        Node *t = st->top;
        x = t->data;
        st->top = t->next;
        delete t;
    }

    return x;
}

void display(Node *st){
    Node *t = st->top;

    cout << "Stack:" << endl;
    
    while(t){
        cout << t->data << endl;
        t = t->next;
    }

    cout << endl;
}

int main(){
    Node stack;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    display(&stack);

    pop(&stack);
    display(&stack);

    return 0;
}