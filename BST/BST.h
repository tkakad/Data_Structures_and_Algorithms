#include <iostream>
#include <vector>

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

TreeNode *create_BST(vector<int> arr){
    if(arr.size() == 0)
        return NULL;
    
    TreeNode *root = new TreeNode(arr[0]);
    TreeNode *t = root;

    int i = 1;

    while(i < arr.size()){
        if(t->data == arr[i]){
            cout << "The number already exists in the tree" << endl;
            i++;
            continue;
        }
        else if(arr[i] > t->data){
            if(t->right == NULL){
                TreeNode *p = new TreeNode(arr[i]);
                t->right = p;
                t = root;
                i++;
            }
            else
                t = t->right;
        }
        else{
            if(t->left == NULL){
                TreeNode *p = new TreeNode(arr[i]);
                t->left = p;
                t = root;
                i++;
            }
            else
                t = t->left;
        }
    }
    
    return root;
}

TreeNode *create_tree(){
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

// Needs to be fixed!

// TreeNode* recursive_insert_BST(TreeNode* tree, int num){
//     TreeNode *t;

//     if(!tree){
//         t = new TreeNode(num);
//         return t;
//     }

//     if(num < tree->data)
//         tree->left = recursive_insert_BST(tree->left, num);
    
//     if(num > tree->data)
//         tree->right = recursive_insert_BST(tree->right, num);
    
//     return t;
// }

TreeNode *iterative_insert_BST(TreeNode *root){
    int x;

    cout << "Enter the number you want to insert in the BST (iteratively): ";
    cin >> x;
    cout << endl;

    TreeNode *t = root;
    
    while(true){
        if(t->data == x){
            cout << "The number already exsists in the tree!" << endl;
            return root;
        }
        else if(x > t->data){
            if(t->right == NULL){
                TreeNode *p = new TreeNode(x);
                t->right = p;
                return root;
            }
            else
                t = t->right;
                
        }
        else{
            if(t->left == NULL){
                TreeNode *p = new TreeNode(x);
                t->left = p;
                return root;
            }
            else
                t = t->left;
        }
    }

    return root;
}

TreeNode *recursive_search(TreeNode* tree){
    int x;

    cout << "Enter the number to be searched in the tree: ";
    cin >> x;

    if(tree){
        if(x == tree->data)
            return tree;
        else if(x > tree->data)
            recursive_search(tree->right);
        else
            recursive_search(tree->left);
    }

    return NULL;
}

TreeNode *iterative_search(TreeNode* tree){
    int x;
    TreeNode *t = tree;

    cout << "Enter the number to be searched in the tree: ";
    cin >> x;

    while(t){
        if(t->data == x)
            return t;
        else if(t->data > x)
            t = t->left;
        else
            t = t->right;
    }

    return NULL;
}