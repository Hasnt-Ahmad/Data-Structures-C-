#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *Next=NULL;
};
class Queue{
    public:
    Node *f;
    Node *r;
    Queue(){
        f=NULL;
        r=NULL;
    }
    void Enqueue(int val){
        Node* n=new Node;
        n->data=val;
        if(f==NULL){
            r=n;
            f=n;
            r->Next=NULL;
        }
        else{
            r->Next=n;
            r=n;
        }
    }
    void Dequeue(){
        if(f==NULL){
            cout<<"Queue is Empty : "<<endl;
        }
        else{
            Node *temp=f;
            f=f->Next;
            delete temp;
        }
    }
    bool isEmpty(){
      if(f==NULL){
        return true;
        }
      else{
        return false;
        }
      }
    void Display(){
    while(f!=NULL){
      cout<<f->data<<endl;
      f=f->Next;
      }
  }
};
int main(){
  Queue Q1;
  Q1.isEmpty();
  Q1.Enqueue(6);
  Q1.Enqueue(5);
  Q1.Enqueue(4);
  Q1.Display();

}