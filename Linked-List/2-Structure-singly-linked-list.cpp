#include <bits/stdc++.h>
using namespace std;

// Representation: 
// A linked list is represented by a pointer to the first node of the linked list. The first node is called the head. If the linked list is empty, then the value of the head points to NULL. 
// Each node in a list consists of at least two parts: 
// 1) data (we can store integer, strings or any type of data).
// 2) Pointer (Or Reference) to the next node (connects one node to another)


//a linked list node

class Node {
public:
    int data;
    Node* next;
};

//a general use function to print the data values of the linked list
void printList(Node* n)
{
  while(n!=NULL) //this loops will traverse the list till it reaches the null pointer which indicated the end of the list
  {
    cout<<n->data<<" ";
    n=n->next;
  }
}

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
  
}
  
