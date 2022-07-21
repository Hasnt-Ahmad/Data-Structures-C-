#include <algorithm> 
#include<iostream>
#include<string>
using namespace std;
struct Node{
  string data;
  Node *Next=NULL;
  };
class Stack{
    public:
    Node *top;
    Stack(){
      top=NULL;
      }
    public:
      void push(string val){
        Node *n=new Node;
        n->data=val;
        if(top==NULL){
          top=n;
          }
        else  {
          n->Next=top;
          top=n;
          }
        }
      void pop(){
        if(top==NULL){
          cout<<"Underflow : "<<endl;
        }
        else{
        Node *temp=new Node;
        temp=top;
        top=top->Next;
        delete temp;
        }
      }
      string Top(){
          string sign=top->data;
          return sign;
      }
      bool Operator(char op){
        if(op=='^' || op=='-' || op=='+' || op=='*' || op=='/'){
          return true;
          }
        else{
          return false;
          }
        }
      void prefix(string exp){
        for(int i=0;i<exp.length();i++){
            if(Operator(exp[i])){
                string infix;
              string opr1,opr2;
              opr1=Top();pop();
              opr2=Top();pop();
              if(exp[i]=='+'){
                infix+=opr1+exp[i]+opr2;
                push(infix);
                }
              else if(exp[i]=='-'){
                infix+=opr1+exp[i]+opr2;
                push(infix);
                }
              else if(exp[i]=='*'){
                infix+=opr1+exp[i]+opr2;
                push(infix);
                }
              else if(exp[i]=='/'){
                infix+=opr1+exp[i]+opr2;
                push(infix);
                }
              }
            else{
                string s;
                s+=exp[i];
              push(s);
              }
          }
        string infix=Top();
        pop();
        cout<<infix<<endl;
      }
  };
int main(){
  Stack s1;
  string exp="AB+CD-*";
  s1.prefix(exp);
  return 0;
}
