#include<iostream>
using namespace std;
struct Node{
  int data;
  Node *Next=NULL;
  Node *pre=NULL;
  };
class list {
  Node *head;
  Node *tail;
  int length;
  public:
  list(){
    head=tail=NULL;
    length=0;
    }
  void insert(int val){
    Node *n=new Node;
    n->data=val;
    if(head==NULL){
      head=n;
      n->Next=n;
      n->pre=n;
      tail=n;
      length++;
      }
    else{
      tail->Next=n;
      n->pre=tail;
      n->Next=head;
      head->pre=n;
      tail=n;
      length++;
      }
    }
void insert(int val,int pos){
      Node *n=new Node;
      n->data=val;
      Node *temp=new Node;
      temp=head;
      if(pos==1){
        n->Next=head;
        n->pre=tail;
        head=n;
        length++;
        }
        else{
          Node *curr=new Node;
          for(int i=1;i<pos;i++){
            curr=temp;
            temp=temp->Next;
            }
            curr->Next=n;
            n->pre=curr;
            n->Next=temp;
            temp->pre=n;
            if(pos==length+1){
              tail=n;
              }
            length++;
          }
      }
    void print(){
      Node *temp=new Node;
      temp=head;
      for(int i=1;i<=length;i++){
        cout<<temp->data<<endl;
        temp=temp->Next;
        }
      }
    void remove(int pos){
      Node *temp=new Node;
      Node *curr=new Node;
      temp=head;
      if(pos==1){
        head=head->Next;
        head->pre=tail;
        tail->Next=head;
        delete temp;
        length--;
        }
      else{
        for(int i=1;i<pos;i++){
          curr=temp;
          temp=temp->Next;
          }
          curr->Next=temp->Next;
          temp->Next->pre=curr;
          if(pos=length+1){
            tail=curr;
            }
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
  l1.insert(55);
  l1.insert(95,5);
  //l1.insert(77,5);

  return 0;
}