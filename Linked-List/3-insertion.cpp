// There are three methods to insert a new node in linked list
// 1) At the front of the linked list 
// 2) After a given node. 
// 3) At the end of the linked list.
// In this code i have made three different functions for insertion.
//push()-to add a new node at the start of the list. it takes pointer to the head pointer and the new data as the arguments
//insertAfter()-to add a node afer the given node. It takes a previous node and the new data as the arguments
//append()-to add a node at the en dof the list. It takes the pointer to the head pointer adn the new data as the arguments



#include <bits/stdc++.h>
using namespace std;

//a linked list node

class Node {
public:
    int data;
    Node* next;
};

//a general use function to print the data values of the linked list
// The new node is always added before the head of the given Linked List. And newly added node becomes the new head of the Linked List.
void printList(Node* n)
{
  while(n!=NULL)
  {
    cout<<n->data<<" ";
    n=n->next;
  }
  cout<<endl;
}


//adding new node to the front of the list
void push(Node** head_ref,int new_data)
{
  Node* new_node=new Node();
  new_node->data=new_data;
  new_node->next=*head_ref;
  (*head_ref)=new_node;
}
// Time complexity of push() is O(1) as it does a constant amount of work.


//adding a node after a given Node
void insertAfter(Node* prev,int new_data)
{
  if(prev==NULL)
  {
    cout<<"Previous node cannot be null";
    return;
  }
  Node* new_node=new Node();
  new_node->data=new_data;
  new_node->next=prev->next;
  prev->next=new_node;
}
// Time complexity of insertAfter() is O(1) as it does a constant amount of work.


//adding a node at the end of the list
// Since a Linked List is typically represented by the head of it, we have to traverse the list till the end and then change the next to last node to a new node.
void append(Node** head_ref, int new_data)
{
  Node* new_node= new Node();
  new_node->data=new_data;
  new_node->next=NULL;
  
  Node* last=*head_ref;
  
  if(head_ref=NULL)
  {
    *head_ref=new_node;
    return;
  }
  
  while(last->next!=NULL)
  {
    last=last->next;
  }
  last->next=new_node;
}
// Time complexity of append is O(n) where n is the number of nodes in the linked list. Since there is a loop from head to end, the function does O(n) work. 
// This method can also be optimized to work in O(1) by keeping an extra pointer to the tail of the linked list/

int main() 
{
  Node* head=NULL;;
  Node* second=NULL;
  Node* third=NULL;
  
  // allocate 3 nodes in the heap
  head=new Node();
  second=new Node();
  third=new Node();
  // Three blocks have been allocated dynamically.
  
  head->data = 1; // assign data in first node
  head->next = second; // Link first node with the second node
  
  second->data=2; //assign data to second node
  second->next=third; //link second node with the third node
  
  third->data=3; //assign data to the third node
  third->next=NULL; //next pointer the the thirs node is NULL, indicating the end of the list

  printList(head); //calling the printList function to print the dat avalues of the linked list
  
  push(&head,5); //adding 5 to the front of the linked list
  printList(head);
  
  insertAfter(head->next,6); //adding 6 to the next of the head
  printList(head);
  
  append(&head,9); //adding 9 at the end of the list
  printList(head);
}
