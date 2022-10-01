#include <iostream>
#include <string>

using namespace std;

struct Stack{
    int size, top;
    char *s;
};

void display(Stack *st){
    cout << "\nFinal Stack:\n" << endl;

    for(int i = st->top; i >= 0; i--)
        cout << st->s[i] << endl;

    cout << "\ntop: " << st->top << endl << endl;
}

void create(Stack *st, int s){
    st->size = s;
    st->top = -1;
    st->s = new char[st->size];
}

void push(Stack *st, char c){
    if(st->top == st->size - 1)
        cout << "\nStack Overflow\n" << endl;
    else
        st->s[++st->top] = c;
}

int pop(Stack *st){
    int x = -1;

    if(st->top > -1){
        x++;
    }

    st->top--;

    cout << "\npop x: " << x << endl << endl;
    
    return x;
}

char peekTop(Stack *st){
    return st->s[st->top];
}

bool isFull(Stack *st){
    return st->top == st->size - 1;
}

bool isEmpty(Stack *st){
    return st->top == - 1;
}

int main(){
    Stack S;
    
    string str = "(a+b)+(c+d))";
    create(&S, str.length());

    for(int i = 0; str[i] != '\0'; i++){
        cout << "----------Step " << i << "----------\n\n";
        cout << "char: " << str[i] << endl;
        display(&S);

        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(&S, str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(isEmpty(&S)){
                cout << "Parenthesis are not balanced!" << endl;
                return 0;
            }
            if(peekTop(&S) == '(' && str[i] == ')' || peekTop(&S) == '[' && str[i] == ']' || peekTop(&S) == '{' && str[i] == '}'){
                pop(&S);
            }
        }
    }

    if(isEmpty(&S))
        cout << "Parenthesis are balanced!" << endl;
    else
        cout << "Parenthesis are not balanced!" << endl;
}