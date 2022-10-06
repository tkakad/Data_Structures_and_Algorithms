#include <iostream>

using namespace std;

// structure definition for Node

struct Node{
    int data;
    Node *left, *right;

    Node(){
        left = right = NULL;
    }

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// structure definition for Queue

struct Queue{
    int size, rear;
    Node **q;

    Queue(){
        cout << "\nEnter the required size of the queue: ";
        cin >> size;
        cout << endl;
        rear = -1;
        q = new Node*[size];
    }

    bool isFull(){
        return (rear == size - 1);
    }

    bool isEmpty(){
        return (rear == -1);
    }

    void enqueue(Node *x){
        if(isFull())
            cout << "\nQueue Overflow!" << endl;
        else
            q[++rear] = x;
    }

    Node *dequeue(){
        if(isEmpty())
            return NULL;
        else{
            Node *x = q[0];

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

// structure definition for Stack

struct Stack{
    Node *data;
    Stack *next;

    bool isEmpty(Stack **top){
        return *top == NULL;
    }

    void push(Stack **top, Node *p){
        Stack *t = new Stack;
        // cout << "top in push function before: " << *top << endl;
        t->data = p;
        t->next = *top;
        *top = t;
        // cout << "top in push function after: " << *top << endl;
    }

    Node *pop(Stack **top){
        // cout << "top in pop function after: " << *top << endl;
        if(*top == NULL){
            cout << "Stack Underflow!" << endl;
            return NULL;
        }
        else{
            Stack *t = *top;
            Node *p = t->data;
            *top = (*top)->next;
            delete t;
            // cout << "top in pop function after: " << *top << endl;
            return p;
        }
    }

    void display(Stack **top){
        Stack *t = *top;

        cout << "Stack: ";

        while(t){
            cout << t->data << " ";
            t = t->next;
        }

        cout << endl;
    }
};

// Iterative Tree Traversal 

void iterative_preorder(Node *root){
    Stack st;
    Stack *top = NULL;
    Node *temp = root;

    cout << "Iterative Preorder traversal: ";

    while(temp != NULL || !st.isEmpty(&top)){
        if(temp != NULL){
            cout << temp->data << " ";
            // cout << "top entered: " << top << endl;
            st.push(&top, temp);
            // cout << "top returned: " << top << endl;
            temp = temp->left;
        }
        else{
            // cout << "top entered: " << top << endl;
            temp = st.pop(&top);
            // cout << "top returned: " << top << endl;
            if(temp)
                temp = temp->right;
        }
    }
    
    cout << endl;
}

void iterative_inorder(Node *root){
    Stack st;
    Stack *top = NULL;
    Node *temp = root;

    cout << "Iterative Inorder traversal: ";

    while(temp != NULL || !st.isEmpty(&top)){
        // cout << "\nBEFORE:\n" << endl;
        // cout << "temp == NULL --> " << (temp == NULL) << endl;
        // cout << "st.isEmpty(&top) --> " << (st.isEmpty(&top)) << endl;
        // st.display(&top);
        if(temp != NULL){
            st.push(&top, temp);
            temp = temp->left;
        }
        else{
            temp = st.pop(&top);
            cout << temp->data << " ";
            if(temp)
                temp = temp->right;
        }
        // cout << "\nAFTER:\n" << endl;
        // cout << "temp == NULL --> " << (temp == NULL) << endl;
        // cout << "st.isEmpty(&top) --> " << (st.isEmpty(&top)) << endl;
        // st.display(&top);
        // cout << endl;
    }

    cout << endl;
}

// void iterative_postorder(Node *root){
//     Stack left_st, right_st;
//     long int t;
//     Stack *left_top = NULL, *right_top = NULL;
//     Node *temp = root;

//     cout << "Iterative Preorder traversal: ";

//     while(temp != NULL || !left_st.isEmpty(&left_top) || !right_st.isEmpty(&right_top)){
//         if(temp != NULL){
//             left_st.push(&left_top, temp);
//             temp = temp->left;
//         }
//         else{
//             right_st.push(&right_top, left_st.pop(&left_top));
//             temp = temp->right;
//             cout << temp->data << " ";
//         }
//     }
// }

// Recursive Tree Traversal 

void preorder_traversal(Node *tree){
    if(tree){
        cout << tree->data << " ";
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

void inorder_traversal(Node *tree){
    if(tree){
        inorder_traversal(tree->left);
        cout << tree->data << " ";
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(Node *tree){
    if(tree){
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        cout << tree->data << " ";
    }
}