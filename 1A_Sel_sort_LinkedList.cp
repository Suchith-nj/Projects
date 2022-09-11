/* Program to create a single linked list of integers, traverse and sort it in ascending order using selection sort */

#include <bits/stdc++.h>
using namespace std;

// Linked list – creation of nodes
class Node
{
public:
    int value;
    Node *next;
};

void createSlList(Node **head, int new_val)
{

    // To Create single linked list of integers
    Node *new_node = new Node();
    Node *last = *head;

    // Setting up the first node and its next
    new_node->value = new_val;
    new_node->next = NULL;

    // If no list exist before, set the head to the first new node
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    // traversing the list
    while (last->next != NULL)
        last = last->next;

    // set the last added node to be new to add further nodes
    last->next = new_node;
    return;
}

// function to print the linked list

void printSlList(Node *node)
{
    while (node != NULL)
    {
        // traverse and print

        cout << node->value << "->";
        node = node->next;
    }
}

void swap(struct Node** head_ref, struct Node* A, struct Node* B, struct Node* prevB)
{
    // Adjust all the nodes and their links accordingly as swapped
   *head_ref = B;
    prevB->next = A;
    struct Node* temp = B->next;
    B->next = A->next;
    A->next = temp;
}
 
/*function to sort the created linked list using selection sort recursively */
struct Node* SlRecSort(struct Node* head)
{
 
    // if there is only one node
    if (head->next == NULL)
        return head;
     
 
    // store the node having minimum value
    struct Node* min = head;
 
    // store node previous the node previous to min node
    struct Node* prevMin = NULL;
    struct Node* ptr;
 
    // traverse the list till the last node
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
 
        // Update min and prevMin nodes
        if (ptr->next->value < min->value) {
            min = ptr->next;
            prevMin = ptr;
        }
    }
 
    // if min and head are not same,
    // swap the head node with the min node
    if (min != head)
        swap(&head, head, min, prevMin);
 
    // recursively sort the remaining list
    head->next = SlRecSort(head->next);
 
    return head;
}
 

	
int main()
{
    //start the list
    Node *head = NULL;

    // start appending integers to the list

    int LLarr[] = {1, 2, 0, 7, 9, 5, 3, 7, 10, 99, 12, 18, 21, 25, 95, 26};

    for (int i = 0; i < sizeof(LLarr)/sizeof(LLarr[0]); i = i + 1)
    {
        createSlList(&head, LLarr[i]);
    }

    cout << "Linked list before sorting: ";
    printSlList(head);
    cout << endl;

    SlRecSort(head);

    cout << "Linked list after sorting: ";
    printSlList(head);

    return 0;
}
