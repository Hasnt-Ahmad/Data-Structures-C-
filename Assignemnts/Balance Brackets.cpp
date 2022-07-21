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
    void check_parentheses(string st, int N){
    Stack l1(10);
    bool ans = true;
    for (int i = 0; i < N; i++)
        if (st[i] == '(' || st[i] == '[' || st[i] == '{')
            l1.push(st[i]);
        else
        {
            if (!l1.empty())
            {
                char temp = l1.Top();

                l1.pop();

                if (st[i] == ')' && temp != '(')
                {
                    ans = false;
                    break;
                }
                if (st[i] == ']' && temp != '[')
                {
                    ans = false;
                    break;
                }
                if (st[i] == '}' && temp != '{')
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
    if (!l1.empty())
        ans = false;
    if (ans)
        cout << "balanced";
    else
        cout << "Not balanced";
}
int main() {
  string s = "){}([])";
  int N = s.length();
  check_parentheses(s, N);
  return 0;
}