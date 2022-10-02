#include <iostream>
#include <string>

using namespace std;

struct Node{
    char data;
    Node *top, *next;

    Node(){
        top = NULL;
    }

    void push(int num){
        Node *t = new Node;
        
        if(t == NULL)
            cout << "Stack Overflow" << endl;
        else{
            t->data = num;
            t->next = top;
            top = t;
        }
    }

    bool isEmpty(){
        return top == NULL;
    }

    int pop(){
        int x = -1;

        if(isEmpty())
            cout << "Stack Underflow" << endl;
        else{
            Node *t = top;
            x = t->data;
            top = top->next;
            delete t;
        }

        return x;
    }

    void display(){
        Node *t = top;

        cout << "Stack: ";
        
        while(t){
            cout << t->data << " ";
            t = t->next;
        }

        cout << endl << endl;; 
    }
};

bool isOperator(char ch){
    char operators[] = {'+', '-', '*', '/'};
    int size = sizeof(operators)/sizeof(operators[0]);
    
    for(int i = 0; i < size; i++){
        if(ch == operators[i])
            return true;
    }

    return false;
}

int precedence_value(char c){
    if(c == '-' || c == '+')
        return 1;
    else if(c == '/' || c == '*')
        return 2;
    else if(isalpha(c))
        return 3;
}

int main(){
    string input = "a+b+c+d";
    string output = "";
    int precedence = 0;

    Node *itr = new Node;

    cout << "Infix: " << input << endl;

    for(int i = 0; input[i] != '\0'; i++){
        char c = input[i];

        cout << "\n--------Step " << i << "--------\n" << endl;

        cout << "character: " << c << endl;

        if(isalpha(c))
            output += c;
        else if(isOperator(c)){
            if(itr->isEmpty())
                itr->push(c);
            else{
                char top_val = itr->top->data;

                cout << "\nprecedence_value(top_val): " << precedence_value(top_val) << endl;
                cout << "precedence_value(c): " << precedence_value(c) << endl;
                
                while(precedence_value(top_val) >= precedence_value(c) and !itr->isEmpty())
                    output += itr->pop();
                
                itr->push(c);
            }
        }

        cout << "\noutput: " << output << endl;

        itr->display();
    }

    while(!itr->isEmpty())
        output += itr->pop();

    cout << "Postfix: " << output << endl;
}

// abc*+de/-