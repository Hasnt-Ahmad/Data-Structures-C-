#include<iostream>
using namespace std;
class Node{
    public:
    char val;
    Node *left;
    Node *right;
    Node(char v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
class S_Node{
    public:
    Node *n;
    S_Node *Next;
    S_Node(Node *temp){
        n=temp;
        Next=NULL;
    }
};
class BST{
    public:
    S_Node *top;
    BST(){
        top=NULL;
    }
    void push(Node *temp){
        if(top==NULL){
            top=new S_Node(temp);
        }
        else{
            S_Node *n=new S_Node(temp);
            n->Next=top;
            top=n;
        }
    }
    void pop(){
        if(top==NULL){
          cout<<"Underflow : "<<endl;
        }
        else{
        S_Node *temp=top;
        top=top->Next;
        delete temp;
        }
      }
    bool Operator(char op){
        if(op=='^' || op=='-' || op=='+' || op=='*' || op=='/'){
          return true;
          }
        else{
          return false;
          }
        }
    Node *Top(){
          return top->n;
      }
    void Post_fix(string exp){
        for(int i=0;i<exp.size();i++){
            if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z'){
                Node *temp=new Node(exp[i]);
                push(temp);
                }
            else if(Operator(exp[i])){
                Node *temp=new Node(exp[i]);
                temp->right=Top();
                pop();
                temp->left=Top();
                pop();
                push(temp);
            }
        }
    }
    void inorder(Node *temp){
        if(temp==NULL){
            return;
        }
        inorder(temp->left);
        cout<<temp->val;
        inorder(temp->right);
    }
};
int main(){
    BST B1;
    string exp="ab+cde+**";
    B1.Post_fix(exp);
    B1.inorder(B1.Top());
}