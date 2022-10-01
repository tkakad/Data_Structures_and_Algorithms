#include <iostream>

using namespace std;

struct Stack{
    int size, top, *s;
};

void create(Stack *st){
    cout << "Enter the size: ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void display(Stack *st){
    cout << "Stack:" << endl;
    for(int i = st->top; i >= 0; i--){
        cout << st->s[i] << endl;
    }
    cout << endl;
}

void push(Stack *st, int x){
    if(st->top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st){
    int x = -1;

    if(st->top > -1){
        x = st->s[st->top];
        st->top--;
    }
    else
        cout << "Stack Underflow!" << endl;

    return x;
}

bool isFull(Stack *st){
    return st->top == st->size - 1;
}

bool isEmpty(Stack *st){
    return st->top == - 1;
}

int main(){
    Stack st;
    create(&st);

    push(&st, 10);
    
    cout << "\npush(&st, 10)\n" << endl;
    display(&st);
    
    push(&st, 20);

    cout << "push(&st, 10)\n" << endl;
    display(&st);
    
    push(&st, 30);
    
    cout << "push(&st, 10)\n" << endl;
    display(&st);
    
    push(&st, 40);

    cout << "push(&st, 10)\n" << endl;
    display(&st);

    cout << "pop(&st)" << endl;

    cout << endl;
    pop(&st);
    display(&st);

    cout << "pop(&st)" << endl;

    cout << endl;
    pop(&st);
    display(&st);

    cout << "pop(&st)" << endl;

    cout << endl;
    pop(&st);
    display(&st);

    cout << "pop(&st)" << endl;

    cout << endl;
    pop(&st);
    display(&st);

    return 0;
}