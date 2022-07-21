#include<iostream>
using namespace std;
struct Node{
  int data;
  Node *Next=NULL;
  };
class list{
  Node *head;
  int length;
  public:
  list(){
    head=NULL;
    length=0;
    }
  void insert(int val){
    Node *n=new Node;
    n->data=val;
    if(head==NULL){
    head=n;
    length++;
    }
    else{
      n->Next=head;
      head=n;
      length++;
      }
    }
 void remove(int pos){
      if(pos==1){
        Node *temp=new Node;
        temp=head;
        head=head->Next;
        delete temp;
        length--;
        }
      }
    void get(int pos){
      Node *temp=new Node;
      temp=head;
      for(int i=1;i<pos;i++){
        temp=temp->Next;
        }
      cout<<temp->data<<endl;
      }
    bool is_Empty(){
      if(head==NULL){
        cout<<"Underflow : "<<endl;
        return true;
        }
      else{
        return false;
        }
      }
  };
class Stack{
  public:
  list l1;
  void push(int val){
    l1.insert(val);
    }
  void pop(){
    if(l1.is_Empty()){
      return;
    }
    else{
    l1.remove(1);
    }
    }
  void top(){
    if(l1.is_Empty()){
      return;
      }
    else{
    l1.get(1);
    }
    }
  };
int main() {
  Stack s1;
  s1.push(25);
  s1.push(44);
  s1.pop();
  s1.top();

  return 0;
}