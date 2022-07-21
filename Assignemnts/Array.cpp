#include<iostream>
using namespace std;
class Array{
    int *arr;
    int size;
    int length;
    int *p;
    int *temp;
    public:
    Array(int s){
        size=s;   
        arr=new int[size]; 
        length=0;
        p=arr;
        temp=p;
    }
    void Insert(int val){
        if(length==size){
            cout<<"Array is Full"<<endl;
            return;
        }
        *p=val;
        p++;
        length++;
    }
    bool find(int val){
        p=arr;
        for(int i=0;i<length-1;i++){
            if(*p==val){
                return true;
            }
            p++;
        }
        return false;

    }
     void get(int pos){
        p=arr;
        for(int i=0;i<pos-1;i++){
            p++;
        }
        cout<<*p;
    }
     void insert(int val,int pos){
        if(length==size){
            cout<<"Array is Full"<<endl;
            return;
          }
        if(pos > size || pos <= 0){
            cout<<"Index Out Of Bounds : "<<endl;
            return;
        }
        if((length == 0 && pos != 1) || (length != 0 && pos > length+1)){
            cout<<"Invalid Position : "<<endl;
            return;
        }
        p=arr;
        for(int i=0;i<pos-1;i++){
            p++;
        }
         if(pos==length+1){
          *p=val;
          return;
          }
        for(int i=1;i<length;i++){
            temp++;
        }
        while(temp>=p){
            *(temp+1)=*temp;
            temp--;
            }
        *p=val;
        length++;
    }
    void update(int val,int pos){
        if(pos>length){
            cout<<"Position Does Not Exist : "<<endl;
            return;
        }
        p=arr;
        for(int i=0;i<pos-1;i++){
            p++;
        }
        *p=val;
    }
    void remove(int pos){
	
	p=arr;

	for(int i=0;i<pos-1;i++){
	    p++;
	}

	temp=p;

	for(int i=pos-1;i<length;i++){
	*temp=*(temp+1);
	temp++;
	}

	length--;
	}
    void print(){
        p=arr;
        for(int i=0;i<length;i++){
            cout<<*p<<"  ";
            p++;
        }
        cout<<endl;
    }
    bool is_Full(){
        if (length==size){
            return true;
        }
        else {
            return false;
        }
    }
    bool is_Empty(){
        if (length==0){
            return true;
        }
        else {
            return false;
        }
    }
    int Length(){
        return length;
    }
    void sort(){
        p=arr;
        int  t;
        for (int i = 0; i < length; i++) {
  
            for (int j = i + 1; j < length; j++) {
  
                if (*(p + j) < *(p + i)) {
  
                    t = *(p + i);
                    *(p + i) = *(p + j);
                    *(p + j) = t;
                }
            }
        }
    }
    void reverse(){
  
        p = arr;
        int *p2 = arr+length-1;
        while (p < p2) {
            swap(*p, *p2);
                p++;
                p2--;
        }
    }
};
int main(){
 Array A1(5);
 A1.Insert(2);
 A1.Insert(1);
 A1.Insert(4);
 A1.Insert(3);
 A1.print();
 A1.reverse();
 A1.print();
}