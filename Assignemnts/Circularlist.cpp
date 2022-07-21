#include<iostream>
using namespace std;
struct Node{
  int data;
  Node *Next;
  };
class list{
  Node *head;
  Node *temp;
  Node *tail;
  int length;
  public:
  list(){
    head=temp=tail=NULL;
    length=0;
    }
  void insert(int val){
    Node *n=new Node;
    n->data=val;
    if(head==NULL){
      head=n;
      temp=head;
      n->Next=head;
      length++;
      }
    else{
      temp->Next=n;
      n->Next=head;
      tail=n;
      temp=n;
      length++;
      }
    }
 void insert(int val,int pos){
    Node *n=new Node;
    n->data=val;
    temp=head;
    if(pos==1){
      n->Next=head;
      head=n;
      tail->Next=head;
      length++;
      }
    else if(pos==length+1){
      for(int i=1;i<length;i++){
        temp=temp->Next;
        }
        temp->Next=n;
        n->Next=head;
        tail=n;
        length++;
      }
    else{
      Node *curr=new Node;
      for(int i=1;i<pos;i++){
        curr=temp;
        temp=temp->Next;
        }
        curr->Next=n;
        n->Next=temp;
        length++;
      }   
    }
void remove(int pos){
    temp=head;
    if(pos==1){
      head=head->Next;
      tail->Next=head;
      delete temp;
      length--;
      }
    else{
      Node *curr=new Node;
      for(int i=1;i<pos;i++){
        curr=temp;
        temp=temp->Next;
        }
        if(pos==length){
        tail=curr;
        tail->Next=head;
      }
      curr->Next=temp->Next;
      delete temp;
      length--;
      }
    }
  };
int main() {
  list l1;
  l1.insert(22);
  l1.insert(33);
  l1.insert(44);
  l1.insert(55,1);
  l1.insert(77,5);
  l1.remove(5);

  return 0;
}