#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left=NULL;
    Node *right=NULL;
};
class Tree{
    public:
    Node *root;
     Tree(){
         root=NULL;
     }
    void insert(int val){
        insert(val,root);
    }
    Node *insert(int val,Node *node){
        Node *n=new Node;
        n->data=val;
        if(root==NULL){
            root=n;
            return root;
        }
        if(node==NULL){
            node=n;
            return node;
        }
        if(val==node->data){
          cout<<"Value Already Exist"<<endl;
            return node;
          }
        else if(node->data>val){
            if(node->left!=NULL){
                insert(val,node->left);
            }
            else{
                node->left=n;
            }
        }
        else if(node->data<val){
                if(node->right!=NULL){
                    insert(val,node->right);
                }
                else{
                    node->right=n;
                }
            }
    }
    Node *search(int val,Node *node){
        if(node==NULL){
            return node;
        }
        else if (node->data==val){
            return node;
        }
        else if(node->data>val){
            return search(val,node->left);
        }
        else if (node->data<val){
            return search(val,node->right);
        }
    }
    Node *parent(Node* curr,int val,Node* p){
        if(curr==NULL){
            cout<<"Parent Does Not Exist : "<<endl;
            return NULL;
        }
        else if(curr->data==val){
            return p;
        }
        else {
            if(curr->data>val){
                parent(curr->left,val,curr);
            }
            else{
                parent(curr->right,val,curr);
            }
        }
    }
    Node *succ(Node* root,int val){
        Node*n=search(val,root);
        if(n->right!=NULL){
            Node *temp=n->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            cout<<"Succ "<<temp->data<<endl;
        }
        else{
            Node*pa=parent(root,n->data,NULL);
            while(n->data>pa->data){
                pa=parent(root,pa->data,NULL);
                 if(pa==NULL){
                cout<<"Does Not Exist : "<<endl;
                return pa;
            }
            }
            cout<<"PA : "<<pa->data<<endl;
            return pa;
            }
        }
    void Inorder(Node *temp){
        if(temp==NULL){
            return;
        }
        Inorder(temp->left);
        cout<<temp->data<<" ";
        Inorder(temp->right);
    }
    Node* Delete(Node *root,int val){
        if(root==NULL){
            return root;
        }
        Node *n=search(val,root);
        if(n->right==NULL & n->left==NULL){
            delete n;
            return NULL;
        }
        else if(n->right!=NULL){
            Node *temp=n->right;
            n->data=temp->data;
            delete temp;
            return n;
        }
        else if(n->left!=NULL){
            Node *temp=n->left;
            n->data=temp->data;
            delete temp;
            return n;
        }
        Node *succ1=succ(root,n->data);
        n->data=succ1->data;
        n->right=Delete(n->right,succ1->data);
        return root;
    }
     void Preorder(Node *temp){
        if(temp==NULL){
            return;
        }
        cout<<temp->data<<" ";
        Preorder(temp->left);
        Preorder(temp->right);
    }
    void Postorder(Node *temp){
        if(temp==NULL){
            return;
        }
        Postorder(temp->left);
        Postorder(temp->right);
        cout<<temp->data<<" ";
    }
    int Depth(Node* root)  {  
        if (root == NULL)  
            return -1;  
        else
        {  
        int lDepth = Depth(root->left);  
        int rDepth = Depth(root->right);  
        int maxDepth=max(lDepth,rDepth);
            return(maxDepth+1); 
        }  
    }
    int Balance_Factor(Node *n,int val){
        Node *q=search(val,n);
        return (Depth(q->left)-Depth(q->right));

    }
};
int main(){
    Tree T1;
    T1.insert(30);
    T1.insert(5);
    T1.insert(35);
    T1.insert(32);
    T1.insert(40);
    T1.insert(45);
    cout<<T1.Balance_Factor(T1.root,30);
}