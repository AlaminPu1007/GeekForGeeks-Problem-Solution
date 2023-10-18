// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://takeuforward.org/data-structure/flattening-a-linked-list/
// C++ program for flattening a Linked List
#include <bits/stdc++.h>
using namespace std;

// Linked list node
class Node
{
public:
    int data;
    Node *next, *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *head = NULL;

// An utility function to merge two sorted
// linked lists
Node *merge(Node *a, Node *b)
{
    Node *res = new Node(0);
    Node *temp = res;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            a = a->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = b;
            b = b->bottom;
            temp = temp->bottom;
        }
    }

    if (a != NULL)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }

    return res->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}

// Utility function to insert a node at
// beginning of the linked list
Node *push(Node *head_ref, int data)
{

    // Allocate the Node & Put in the data
    Node *new_node = new Node(0);

    new_node->data = data;
    new_node->next = NULL;

    // Make next of new Node as head
    new_node->bottom = head_ref;

    // Move the head to point to new Node
    head_ref = new_node;

    return head_ref;
}

void printList(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

// Driver's code
int main()
{

    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        | |	 |	 |
        V V	 V	 V
        7 20 22 35
        |		 |	 |
        V		 V	 V
        8		 50 40
        |			 |
        V			 V
        30			 45
    */
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->next = push(head->next, 20);
    head->next = push(head->next, 10);

    head->next->next = push(head->next->next, 50);
    head->next->next = push(head->next->next, 22);
    head->next->next = push(head->next->next, 19);

    head->next->next->next = push(head->next->next->next, 45);
    head->next->next->next = push(head->next->next->next, 40);
    head->next->next->next = push(head->next->next->next, 35);
    head->next->next->next = push(head->next->next->next, 20);

    // Function call
    Node *res = flatten(head);

    printList(res);
    return 0;
}

// This code is contributed by rajsanghavi9.
