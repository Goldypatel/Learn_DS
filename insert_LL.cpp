/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
        
        node (int data){
            this -> data =data;
            this -> next = nullptr;
        }
};

void insertAtHead(node* &head , int d){
    node* n1 = new node(d);
    n1 -> next = head;
    head = n1;
}

void insertAtEnd(node* &tail , int d){
    node* n1 = new node(d);
    n1 ->next =nullptr;
    tail -> next = n1;
    tail =tail ->next ;
}

void insertAtPos(node* &head,node* &tail , int pos , int data){
    if(pos == 1){
        insertAtHead(head, data);
    }
    node* n1 = new node(data);
    node* temp = head;
    for(int i= 1 ; i < pos -1 && temp != nullptr ; i++){
        temp =temp->next;
    }
    
    if(temp ==nullptr){
        insertAtEnd(tail,data);
    }
    
    n1 ->next = temp ->next;
    temp->next = n1;
}

void printN(node* &head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp =temp->next;
    }
}

int main()
{
    node* node1 = new node(2);
    node* node2 = new node(9);
    node* head =node1;
    node* tail = node2;
    insertAtHead(head , 1);
    insertAtEnd(tail,10);
    insertAtPos(head, tail, 2, 3);
    printN(head);
    
    

    return 0;
}