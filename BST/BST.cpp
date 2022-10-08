#include "BST.h"

int main(){
    TreeNode *tree = create_BST();

    cout << "Inorder traversal: ";
    inorder_traversal(tree);
    cout << endl;œ
    level_order_traversal(tree);
    cout << endl;

    insert_BST(tree);
    cout << "Inorder traversal: ";
    inorder_traversal(tree);
    cout << endl;
    level_order_traversal(tree);
    cout << endl;

    insert_BST(tree);
    cout << "Inorder traversal: ";
    inorder_traversal(tree);
    cout << endl;
    level_order_traversal(tree);
    cout << endl;

    insert_BST(tree);
    cout << "Inorder traversal: ";
    inorder_traversal(tree);
    cout << endl;
    level_order_traversal(tree);
    cout << endl;

    return 0;
}