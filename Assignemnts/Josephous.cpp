#include<iostream>
using namespace std;
struct Node{
  int data;
  Node *Next;
  };
  class list{
    Node* head;
    Node *tail;
    Node *temp;
    Node *curr;
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
        tail=head;
        temp=head;
        length++;
        }
      else{
        tail->Next=n;
        n->Next=head;
        tail=n;
        length++;
        }
      }
    void remove(int pos){
      for(int i=1;i<pos;i++){
        curr=temp;
        temp=temp->Next;
        }
        curr->Next=temp->Next;
        delete temp;
        length--;
        temp=curr->Next;
      }
    int Length(){
      return length;
      }
    int josephous(int n,int m){
        for(int i=1;i<=n;i++){
            insert(i);
        }
      while(Length()!=1){
        int pos=1;
        for(int i=1;i<=m;i++){
          pos++;
          }
        remove(pos);
        }
      return (temp->data);
      }
    };
int main() {
  list l1;
  int m,n;
  cout<<"Enter N"<<endl;
  cin>>n;
  cout<<"Enter M "<<endl;
  cin>>m;
  cout<<l1.josephous(n,m);
  return 0;
}