#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;

    TreeNode(){
        left = right = NULL;
    }

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

struct Node{
    TreeNode *data;
    Node *next;

    Node(){
        next = NULL;
    }

    Node(TreeNode *t){
        data = t;
        next = NULL;
    }
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
        TreeNode *t = new TreeNode;

        if(t == NULL){
            delete t;
            return true;
        }

        delete t;
        return false;
    }

    void enqueue(TreeNode *t){
        if(isFull())
            cout << "Queue overflow!" << endl;
        else{
            Node *p = new Node;
            p->data = t;
            p->next = NULL;

            if(isEmpty())
                front = p;
            else
                rear->next = p;
            
            rear = p;
        }
    }

    TreeNode *dequeue(){
        if(isEmpty())
            return NULL; // Queue underflow
        else{
            Node *t = front;
            TreeNode *p = t->data;
            if(front == rear)
                front = rear = NULL;
            else
                front = front->next;
            delete t;
            return p;
        }
    }
};

TreeNode *create_BST(){
    Queue Q;
    TreeNode *t, *root = new TreeNode;

    cout << "\nEnter the value of the root node: ";
    cin >> root->data;
    cout << endl;

    Q.enqueue(root);

    int l_val, r_val;

    while(!Q.isEmpty()){
        t = Q.dequeue();

        cout << "Enter the value of the left child of " << t->data << ": ";
        cin >> l_val;
        cout << endl;

        if(l_val != -1){
            TreeNode *l = new TreeNode(l_val);
            t->left = l;
            Q.enqueue(t->left);
        }

        cout << "Enter the value of the right child of " << t->data << ": ";
        cin >> r_val;
        cout << endl;

        if(r_val != -1){
            TreeNode *r = new TreeNode(r_val);
            t->right = r;
            Q.enqueue(t->right);
        }
    }

    return root;
}

void level_order_traversal(TreeNode *root){
    if(root == NULL){
        cout << "Empty Tree!" << endl;
    }
    else{
        TreeNode *t = root;
        Queue Q;
        Q.enqueue(t);

        cout << "Level Order Traversal: ";

        while(!Q.isEmpty()){
            t = Q.dequeue();
            cout << t->data << " ";

            if(t->left)
                Q.enqueue(t->left);
            
            if(t->right)
                Q.enqueue(t->right);
        }
        
        cout << endl;
    }
}

void inorder_traversal(TreeNode *t){
    if(t){
        inorder_traversal(t->left);
        cout << t->data << " ";
        inorder_traversal(t->right);
    }
}

void insert_BST(TreeNode *root){
    int x;
    bool found = false;

    cout << "Enter the number you want to insert in the BST: ";
    cin >> x;
    cout << endl;

    TreeNode *t = root;
    
    while(!found){
        if(t->data == x){
            cout << "The number already exsists in the tree!" << endl;
            found = true;
        }
        else if(x > t->data){
            if(t->right == NULL){
                TreeNode *p = new TreeNode;
                p->data = x;
                t->right = p;
                found = true;
            }
            else
                t = t->right;
        }
        else{
            if(t->left == NULL){
                TreeNode *p = new TreeNode;
                p->data = x;
                t->left = p;
                found = true;
            }
            else
                t = t->left;
        }
    }
}