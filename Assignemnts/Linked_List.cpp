#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
private:
    node *head,*tail;
    int length;
public:
    list()
    {
        head = NULL;
        tail = NULL;
        length=0;
    }

    void createlist(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
            length++;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
            length++;
        }
    }
    void print(){
        if(length==0){
            cout<<"List Is Empty : "<<endl;
        }
        else{
            node *temp=new node;
            temp=head;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
            cout<<endl;
        }
    }
       bool search(int val){
           if(length==0){
            cout<<"List Is Empty : "<<endl;
        }
            else{
                node *temp=head;
                for(int i=1;i<length;i++){
                    if(temp->data==val){
                    return true;
                    }
                    temp=temp->next;
                }
                if(temp->data!=val){
                    return false;
                }
            }
        } 
    void remove(int pos){
        if(length==0){
            cout<<"List Is Empty : "<<endl;
        }
        else{
            node* temp=head;
            node*prev;
        if(pos==1){
            head=head->next;
            delete temp;
            length=length-1;
        }
        else{
            for(int i=1;i<pos;i++){
                prev=temp;
                temp=temp->next;
            }
            if(temp->next==NULL){
                tail=prev;
                prev->next=NULL;
                delete temp;
                length=length-1;
            }
            else{
            prev->next=temp->next;
            delete temp;
            length=length-1;
            }
        }
    }
}   
     void insert(int val,int pos){
        if(length==0){
            cout<<"List Is Empty : "<<endl;
        }
        else{
            node *n=new node;
            node *temp=new node;
            temp=head;
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            n->data=val;
            n->next=temp->next;
            temp->next=n;
            length++;
            }
        }
    void swap(int x,int y){
        node *p=new node;
        node *pre=new node;
        node*temp=new node;
        p=head;
        pre=NULL;
        int i=1;
        int j=1;
        while(p!=NULL && i!=x){
            pre=p;
            p=p->next;
            i++;
        }
        node *pX=p;
        node *preX=pre;
        p=head;
        pre=NULL;
        while(p!=NULL && j!=y){
            pre=p;
            p=p->next;
            j++;
        }
        node *pY=p;
        node *preY=pre;
        temp=pY->next;
        pY->next=pX->next;
        pX->next=temp;
        if(preX==NULL){
            pY=head;
            preY->next=pX;
        }
        if(preY==NULL){
            pX=head;
            preX->next=preY;
        }
        if(preX!=NULL && preY!=NULL){
            preX->next=pY;
            preY->next=pX;
        }
    }
};

int main()
{
    int size,choice;
    bool quit=true;
    list l1;
    while(quit){
    cout<<"Enter Operation To Perform On List : "<<endl;
    cout<<"1.Create List : "<<endl;
    cout<<"2.Add Element In THe List : "<<endl;
    cout<<"3.Remove Element From The List : "<<endl;
    cout<<"4.Search Element In The List : "<<endl;
    cout<<"5.Print List : "<<endl;
    cout<<"6.Swap Nodes : "<<endl;
    cout<<"7.Quit "<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"Enter Size Of List :" <<endl;
        cin>>size;
        int numb;
        cout<<"Enter Elements In List : "<<endl;
         for(int i=1;i<=size;i++){
            cin>>numb;
            l1.createlist(numb);
        }
    }
    else if(choice==2){
        int numb,pos;
        cout<<"Enter Element And Position To Add IT To List : "<<endl;
        cin>>numb;
        cin>>pos;
        l1.insert(numb,pos);
    }
    else if(choice==3){
        int pos;
        cout<<"Enter Position To Remove Element: "<<endl;
        cin>>pos;
        l1.remove(pos);
    }
    else if(choice==4){
        int numb;
        cout<<"Enter Element To Search : "<<endl;
        cin>>numb;
        l1.search(numb);
    }
     else if(choice==5){
        l1.print();
    }

    else if(choice==6){
        l1.swap(2,4);
    }
    else if(choice==7){
        quit=false;
    }
    }
    return 0;
}