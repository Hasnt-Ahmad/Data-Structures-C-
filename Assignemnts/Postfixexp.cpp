#include<iostream>
#include <string>
#include<cmath>
using namespace std;
struct Node{
  int data;
  Node *Next=NULL;
  };
class Stack{
    public:
    Node *top;
    Stack(){
      top=NULL;
      }
    public:
      void push(char val){
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
      int Top(){
          int sign=top->data;
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
      void postfix(string exp){
        for(int i=0;i<exp.length();i++){
          if(Operator(exp[i])){
             int opr1,opr2;
                opr2=Top();
                pop();
                opr1=Top();
                pop();
              if(exp[i]=='+'){
                int ans=opr1+opr2;
                push(ans);
                }
              else if(exp[i]=='-'){
                int ans=opr1-opr2;
                push(ans);
                }
             else if(exp[i]=='*'){
                int ans=opr1*opr2;
                push(ans);
                }
                 else if(exp[i]=='/'){
                int ans=opr1/opr2;
                push(ans);
                }
                 else if(exp[i]=='^'){
                int ans=pow(opr1,opr2);
                push(ans);
                }
          }
        else{
          int num;
          num=exp[i]-'0';
          push(num);
          }
        }
        cout<<Top()<<endl;
        pop();
      }
  };
int main(){
  string exp="623+-382/+*2^3+";
  Stack s1;
  s1.postfix(exp);
  return 0;
}