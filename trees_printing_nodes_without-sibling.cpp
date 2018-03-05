#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
public:
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

string value;
stack<int> s;

node* buildTree(){
    int d;
    cin>>d;
	node*root = new node(d);
    
    cin>>value;
	
	if(value=="true"){
	    
		root->left = buildTree();
		
		//return root;
	}
	cin>>value;
	
	if(value=="true"){
		
		root->right = buildTree();
		
		//return root;
	}
	if(root->left!=NULL&&root->right==NULL){
		    s.push(root->left->data);
		}
		
	if(root->left==NULL&&root->right!=NULL){
		    s.push(root->right->data);
		}
	return root;
	if(value=="false"){
	    return NULL;
	}
}

node* levelorderinput(){
    int d;
    cin>>d;
    node *root = new node(d);
    
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        
        int d1,d2;
        cin>>d1>>d2;
        
        if(d1!=-1){
            temp->left = new node(d1);
            q.push(temp->left);
        }
        if(d2!=-1){
            temp->right = new node(d2);
            q.push(temp->right);
        }
        if(d1==-1&&d2==-1){
            cout<<temp->data<<" ";
        }
    }
    return root;
}

void printTree(node*root){
	//Preorder
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
    
    node *root = NULL;

    root = buildTree();
    //printTree(root);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}


/*if(root->left!=NULL&&root->right==NULL){
		    cout<<root->left->data<<" ";
		}*/
		
		/*if(root->left==NULL&&root->right!=NULL){
		    cout<<root->right->data<<" ";
		}*/