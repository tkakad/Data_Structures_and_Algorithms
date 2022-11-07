#include "BST.h"

int main(){
    // pre-order traversal to BST

    TreeNode *temp_tree = BST_from_preorder({30,20,10,15,25,40,50,45});
    cout << "\nInorder traversal: ";
    inorder_traversal(temp_tree);
    cout << endl;
    level_order_traversal(temp_tree);
    cout << endl;

    // int temp;
    // TreeNode *tree = NULL;
    // tree = recursive_insert_BST(tree, 10);
    // recursive_insert_BST(tree, 5);
    // recursive_insert_BST(tree, 20);
    // recursive_insert_BST(tree, 8);
    // recursive_insert_BST(tree, 30);

    // // int num;
    // // vector<int> numbers = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    // // TreeNode *tree = create_BST(numbers);
    
    // // TreeNode *tree = create_tree();

    // cout << "\nInorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    // // Recursive insertion function needs to be fixed

    // // cout << "Enter the number to be inserted into the BST (recursively): ";
    // // cin >> num; 
    // // tree = recursive_insert_BST(tree, num);
    // // cout << "Inorder traversal: ";
    // // inorder_traversal(tree);
    // // cout << endl;
    // // level_order_traversal(tree);
    // // cout << endl;

    // tree = iterative_insert_BST(tree);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    // tree = iterative_insert_BST(tree);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    // cout << "Enter the number to be deleted: ";
    // cin >> temp;
    // delete_node(tree, temp);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    // cout << "Enter the number to be deleted: ";
    // cin >> temp;
    // delete_node(tree, temp);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    // cout << "Enter the number to be deleted: ";
    // cin >> temp;
    // delete_node(tree, temp);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    // cout << "Enter the number to be deleted: ";
    // cin >> temp;
    // delete_node(tree, temp);
    // cout << "Inorder traversal: ";
    // inorder_traversal(tree);
    // cout << endl;
    // level_order_traversal(tree);
    // cout << endl;

    return 0;
}