
#include <iostream>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
    
    node(int data){
        this ->data = data;
        this -> prev= nullptr;
        this -> next= nullptr;
        }
};

void insertAtHead(node* &head, int data){
    node* n1= new node(data);
    if(head == nullptr){
        head = n1;
    }
    head->prev = n1;
    n1->next =head;
    head =n1;
       
}

void insertAtend(node* &tail, int data){
    node* n1= new node(data);
    
    tail->next = n1;
    n1->prev = tail;
    tail =n1;
}

void insertAtpos(node* &head,node* &tail, int pos, int data){
    if(pos==1){
        insertAtHead(head,data);
    }
    
    node* n1 = new node(data);
    node* curr =head;
    node* before =nullptr;
    for(int i=1;i<=pos ;i++){
        before =curr;
        curr=curr->next;
    }
    
    if(curr->next==nullptr){
        insertAtend(tail,data);
    }
    
    before->next =n1;
    n1->prev = before;
    n1->next = curr;
    curr->prev=n1;
    
}

void printN(node* &head){
    node* temp = head;
    while(temp->next != nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
}
int main()
{
   node* nodeH = new node(2);
   node* nodeT =new node(8);
   node* head=nodeH;
   node* tail = nodeT;
   head ->next = tail;
   tail->prev -head;
   
   insertAtHead(head, 1);
   insertAtend(tail,9);
   insertAtpos(head, tail, 3,3);
   printN(head);


    return 0;
}