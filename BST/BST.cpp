#include "BST.h"

int main(){
    int num;
    vector<int> numbers = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    TreeNode *tree = create_BST(numbers);
    // TreeNode *tree = create_tree();

    cout << "\nInorder traversal: ";
    inorder_traversal(tree);
    cout << endl;
    level_order_traversal(tree);
    cout << endl;

    // Recursive insertion function needs to be fixed

    // cout << "Enter the number to be inserted into the BST (recursively): ";
    // cin >> num; 
    // tree = recursive_insert_BST(tree, num);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    tree = iterative_insert_BST(tree);
    cout << "Inorder traversal: ";
    inorder_traversal(tree);
    cout << endl;
    level_order_traversal(tree);
    cout << endl;

    tree = iterative_insert_BST(tree);
    cout << "Inorder traversal: ";
    inorder_traversal(tree);
    cout << endl;
    level_order_traversal(tree);
    cout << endl;

    return 0;
}