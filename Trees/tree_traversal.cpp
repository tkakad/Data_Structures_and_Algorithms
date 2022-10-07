#include "tree_traversal.h"

int main(){
    Queue Q(10);
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

    cout << "\nInorder traversal: ";
    inorder_traversal(root);
    cout << endl;

    cout << "\nPostorder traversal: ";
    postorder_traversal(root);
    cout << endl << endl;

    iterative_preorder(root);
    cout << endl;

    iterative_inorder(root);
    cout << endl;

    level_order_traversal(root);
    cout << endl;

    return 0;
}