// To delete a node from the linked list, we need to do the following steps. 
// 1) Find the previous node of the node to be deleted. 
// 2) Change the next of the previous node. 
// 3) Free memory for the node to be deleted.

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void deleteNode(Node** head_ref, int key)
{
  // Store head node
  Node* temp=*head_ref;
  Node* prev=NULL;
  
  // If head node itself holds
  // the key to be deleted
  if(temp!=NULL && temp->data==key)
  {
    *head_ref=temp->next;
    delete temp;
    return;
  }
  
  while(temp!=NULL && temp->data!=key)
  {
    prev=temp;
    temp=temp->next;
  }
  
  if(temp==NULL)
  {
    cout<<"NOT FOUND";
    return;
  }
  prev->next=temp->next;
  delete temp;
}


int main()
{
     
    // Start with the empty list
    Node* head = NULL;
 
    // Add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 5);
 
    puts("Created Linked List: ");
    printList(head);
 
    deleteNode(&head,1);
    puts("\nLinked List after Deletion of 1: ");
     
    printList(head);
     
    return 0;
}
