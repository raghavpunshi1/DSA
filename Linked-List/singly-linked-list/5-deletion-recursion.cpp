// To delete a node of a linked list recursively we need to do the following steps.
// 1. We pass node* (node pointer) as a reference to the function (as in node* &head)
// 2. Now since the current node pointer is derived from the previous node’s next (which is passed by reference) so now if the value of the current node pointer is changed, the previous next node’s value also gets changed which is the required operation while deleting a node (i.e points previous node’s next to current node’s (containing key) next).
// 3. Find the node containing the given value.
// 4. Store this node to deallocate it later using the free() function.
// 5. Change this node pointer so that it points to its next and by performing this previous node’s next also gets properly linked.

#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int info;
    node* link = NULL;
    node() {}
    node(int a)
        : info(a)
    {
    }
};
 
/*
Deletes the node containing 'info' part as val and
alter the head of the linked list (recursive method)
*/
void deleteNode(node*& head, int val)
{
     
    // Check if list is empty or we reach at the end of the list.
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    // If current node is the node to be deleted
    if (head->info == val) {
        node* t = head;
        head = head->link; // If it's start of the node head
                           // node points to second node
        delete (t); // Else changes previous node's link to
                    // current node's link
        return;
    }
    deleteNode(head->link, val);
}

void push(node*& head, int data)
{
    node* newNode = new node(data);
    newNode->link = head;
    head = newNode;
}
 
// Utility function to print
// the linked list (recursive
// method)
void print(node* head)
{
     
    // cout<<endl gets implicitly
    // typecasted to bool value
    // 'true'
    if (head == NULL and cout << endl)
        return;
    cout << head->info << ' ';
    print(head->link);
}
 
int main()
{
    // Starting with an empty linked list
    node* head = NULL;
 
    // Adds new element at the
    // beginning of the list
    push(head, 10);
    push(head, 12);
    push(head, 14);
    push(head, 15);
 
    // original list
    print(head);
 
    deleteNode(head, 20); // Call to delete function
    print(head); // 20 is not present thus no change in the
                 // list
 
    deleteNode(head, 10);
    print(head);
 
    deleteNode(head, 14);
    print(head);
 
    return 0;
}
