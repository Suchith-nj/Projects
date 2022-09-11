//Code to create BST, do in-order traversal and delete the node

#include <iostream>
using namespace std;

// Data Struct for Binary search tree node
struct Node
{
    int value;
    Node *left, *right;
};

// Function to create a new binary tree node with provided value
Node *newNode(int key)
{
    Node *node = new Node;
    node->value = key;
    node->left = node->right = NULL;
    return node;
}

// Function to perform In-order traversal in a binary search tree
void inOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->left);    // first recurse at left  of a subtree
    cout << root->value << " "; // root of the subtree
    inOrderTrav(root->right);   // recurse at right of the subtree
}

// Function to find the minimum value node in the subtree to replace the value of the root to be //deleted as a successor
Node *minValue(Node *current)
{
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Recursive fun to insert values into binary search tree
Node *insert(Node *root, int key)
{
    // if the root is null then create new node and return the same
    if (root == NULL)
    {
        return newNode(key);
    }

    // if the given key is less than the root node then recur at the left subtree
    if (key < root->value)
    {
        root->left = insert(root->left, key);
    }

    // if the given key is more than the root node, recur for the right subtree
    else
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// Iterative function to search in the subtree rooted at temp and set its parent
// this is useful to delete the key node which will be the child of parent node
void findKey(Node *&temp, int key, Node *&parent)
{
    // traverse the tree and search for the key
    while (temp != NULL && temp->value != key)
    {
        // update the parent to the current node
        parent = temp;

        // if the given key is less than the current node, go to the left subtree else right

        if (key < temp->value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
}

// Function to delete a node from a BST
void deleteNode(Node *&root, int key)
{
    // pointer to store the parent of the current node
    Node *parent = NULL;

    // start with the root node
    Node *temp = root;

    // search key in the BST and set its parent pointer
    findKey(temp, key, parent);

    // return if the key is not found in the tree
    if (temp == NULL)
    {
        return;
    }

    // Case 1- Node to be deleted is a leaf node
    if (temp->left == NULL && temp->right == NULL)
    {
        // if the node to be deleted is not a root node, then simply delete that node
        if (temp != root)
        {
            if (parent->left == temp)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        // if the tree has only a root node then set it to null
        else
        {
            root = NULL;
        }
        delete (temp); // to deallocate mem
    }

    // Case 2: node to be deleted has two children
    else if (temp->left && temp->right)
    {
        // find its inOrderTrav successor node
        Node *successor = minValue(temp->right);

        // store successor value
        int val = successor->value;

        deleteNode(root, successor->value);

        // copy value of the successor to the currentent node
        temp->value = val;
    }

    // Case 3: node to be deleted has only one child
    else
    {
        // choose a child node
        Node *child = (temp->left) ? temp->left : temp->right;

        // if the node to be deleted is not a root node, set its parent
        // to its child
        if (temp != root)
        {
            if (temp == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }

        // if the node to be deleted is a root node, then set the root to the child
        else
        {
            root = child;
        }

        delete (temp);
    }
}

int main()
{
    int keys[] = {40, 60, 20, 80, 50, 10, 30, 15, 5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46};
    int n1,n2;

    Node *root = NULL;
    for (int key : keys)
    {
        root = insert(root, key);
    }
    cout << "Binary search tree at the start " << endl;
    inOrderTrav(root);
    cout << endl;
    cout << "Enter the first node to be deleted"<< endl;
    cin >>  n1 ;
    deleteNode(root, n1);
    cout << "Binary search tree after deleting node " << n1 << endl;
    inOrderTrav(root);
    cout << endl;
    cout << "Enter the second node to be deleted"<< endl;
    cin >>  n2 ;
    deleteNode(root, n2);
    cout << "Binary search tree after deleting node " << n2 << endl;
    inOrderTrav(root);
    return 0;
}