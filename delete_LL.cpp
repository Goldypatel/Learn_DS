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
    if(tail!= NULL){
    n1 ->next =nullptr;
    n1 = tail -> next ;
    tail = n1 ;
    }
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
    
    if(temp ==nullptr || temp->next ==nullptr){
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

void deleteFromBeg(node* &head){
    if(head == nullptr){
        cout<<"empty list"<<endl;
    }
    node* temp = head;
    head = head ->next;
    delete temp;
}
void deleteFromElsewhere(node* &head, int pos){
    
    node* curr = head;
    node* prev = NULL;
    for(int i=1 ;i <pos;i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next = curr ->next;
    delete curr;
    
}


int main()
{
    node* node1 = new node(2);
    node* node2 = new node(9);
    node* head =node1;
    node* tail = node2;
    head->next = tail;
    insertAtHead(head , 1);
    insertAtHead(head , 4);
    insertAtEnd(tail,10);
    insertAtEnd(tail,11);
    
    insertAtPos(head, tail, 2, 3);
    printN(head);
    cout<<"after"<<endl;
    deleteFromBeg(head);
    printN(head);
    
    deleteFromElsewhere(head,2);
    cout<<"after"<<endl;
    printN(head);
    

    return 0;
}