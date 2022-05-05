// If the node to be deleted is the root, simply delete it. To delete a middle node, 
// we must have a pointer to the node previous to the node to be deleted.
// So if positions are not zero, we run a loop position-1 times and get a pointer to the previous node.



#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void deleteNode(Node** head_ref,int pos)
{
  if(*head_ref==NULL) return; //if the linked list is empty
  Node* temp=*head_ref; //storing head node
  
  if(pos==0)
  {
    *head_ref=temp->next;
    free(temp); //free old head
    return;
  }
  
  for(int i=0;i<pos-1 && temp!=NULL;i++)     // Find previous node of the node to be deleted
  {
    temp=temp->next;
  }
  if(temp==NULL || temp->next==NULL) return;      // If position is more than number of nodes 
  // Node temp->next is the node to be deleted
  // Store pointer to the next of node to be deleted
  Node* next = temp->next->next;
  
  free(temp->next); // Free memory
  
  temp->next=next;
  
}

int main()
{
 
    // Start with the empty list
    Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
 
    cout << "Created Linked List: ";
    printList(head);
    deleteNode(&head, 3);
    cout<<endl;
    // cout << "\nLinked List after Deletion at position 4: ";
    printList(head);
    return 0;
}
