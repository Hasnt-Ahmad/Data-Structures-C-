#include<iostream>
using namespace std;
class Stack {
  private:
  int *arr;
  int top;
  int size;
  int length;
  public:
  Stack(int s){
    size=s;
    arr=new int[size];
    length=0;
    top=-1;
    }
  void push(int val){
    if(top==size-1){
      cout<<"OverFlow : "<<endl;
      }
    else{
      arr[++top]=val;
      length++;
      }
    }
    void pop(){
      if(top==-1){
        cout<<"underFlow : "<<endl;
        }
      else{
          top--;
          length--;
        }
      }
 int Top(){
      if(top==-1){
        cout<<"UnderFlow : "<<endl;
        return -1;
        }
      else{
        return arr[top];
        }
      }
  bool empty(){
    if(length==0){
      return true;
    }
    else{
    return false;
    }
  }
  };
int main() {
  Stack s(5);
  s.pop();
  s.push(1);
  s.push(4);
  s.push(5);
  s.push(6);
  cout<<s.Top();

  return 0;
}