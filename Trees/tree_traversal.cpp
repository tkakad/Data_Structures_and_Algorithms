#include <iostream>

using namespace std;

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

struct Stack{
    Node *data;
    
};

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

    bool isEmpty(){
        return (rear == -1);
    }

    bool isFull(){
        return (rear == size - 1);
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

// Iterative Tree Traversal 

// ...

int main(){
    Queue Q;
    Node *root = new Node;
    int l_val, r_val;
    
    cout << "Enter the value for the root node: ";
    cin >> root ->data;
    cout << endl;

    Q.enqueue(root);

    while(!Q.isEmpty()){
        Node* addr = Q.dequeue();
    
        cout << "Enter left child value for " << addr->data << ": ";
        cin >> l_val;
        cout << endl;

        if(l_val != -1){
            Node *t = new Node(l_val);
            t->data = l_val;
            addr->left = t;
            Q.enqueue(t);
        }

        cout << "Enter right child value for " << addr->data << ": ";
        cin >> r_val;
        cout << endl;

        if(l_val != -1){
            Node *p = new Node(r_val);
            addr->right = p;
            Q.enqueue(p);
        }
    }

    cout << "Preorder traversal: ";
    preorder_traversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder_traversal(root);
    cout << endl;

    return 0;
}