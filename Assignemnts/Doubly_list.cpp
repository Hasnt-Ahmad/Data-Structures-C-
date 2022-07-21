#include<iostream>
using namespace std;
struct Node{
  int data;
  Node *Next=NULL;
  Node *pre=NULL;
  };
  class list{
    int length;
    Node *temp;
    Node *head;
    public:
    list(){
      temp=NULL;
      head=NULL;
      length=0;
      }
    void insert(int val){
      Node *n=new Node;
      n->data=val;
      if(head==NULL){
        n->Next=NULL;
        head=n;
        temp=head;
        length++;
        }
      else{
        temp->Next=n;
        n->pre=temp;
        temp=n;
        n->Next=NULL;
        length++;
        }
    }
void insert(int val,int pos){
      Node *n=new Node;
      n->data=val;
      Node *curr=new Node;
      temp=head;
      if(pos==1){
        n->Next=head;
        head->pre=n;
        head=n;
        length++;
        }
      else{
      for(int i=1;i<pos;i++){
        curr=temp;
        temp=temp->Next;
        }
        curr->Next=n;
        n->pre=curr;
        n->Next=temp;
        if(pos!=(length+1)){
        temp->pre=n;
        }
        length++;
        }
      }
    void print(){
      temp=head;
      for(int i=1;i<=length;i++){
        cout<<temp->data<<endl;
        temp=temp->Next;
        }
      }
    void remove(int pos){
      if(head==NULL){
        cout<<"List IS Empty : "<<endl;
        }
      else if(pos<=0 or pos>length){
        cout<<"Invalid Position : "<<endl;
        }
      else{
        Node *curr=new Node;
        temp=head;
        if(pos==1){
          head=head->Next;
          head->pre=NULL;
          delete temp;
          length--;
        }
        else{
        for(int i=1;i<pos;i++){
          curr=temp;
          temp=temp->Next;
          }
          curr->Next=temp->Next;
          if(pos!=length){
          temp->Next->pre=curr;
          }
          delete temp;
          length--;
          }
        }
      
      }
      void reverseList()
{
     Node *current=head;
     Node *prev=NULL;
    while(current!=NULL)
    {
        current->pre=current->Next; 
        current->Next=prev;          
        prev=current;                
        current=current->pre;       
    }
        head=prev;
}
void sort(){
      Node *curr=new Node;
      Node *prev1=new Node;
      curr=head;
      while(curr->Next!=NULL){
        prev1=curr;
        curr++;
        if(prev1->data>curr->data){
          prev1->Next=curr->Next;
          curr->Next->pre=prev1;
          curr->Next=prev1;
          prev1->pre=curr;
        }
      }
      cout<<"Done"<<endl;
    }
};
int main() {
  list a1;
  a1.insert(24);
  a1.insert(25);
  a1.insert(88);
  a1.insert(66);
  a1.print();
  a1.sort();
  a1.print();
  return 0;
}