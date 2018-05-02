#include <iostream>
#include <queue>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildtree(){
    int d;
    cin>>d;
    
    if(d!=-1){
        node *root = new node(d);
        root->left = buildtree();
        root->right = buildtree();
        return root;
    }
    else{
        return NULL;
    }
}

void preprint(node *root){
    if(root == NULL){
        return;
    }
    
    else{
        cout<<root->data<<" ";
        preprint(root->left);
        preprint(root->right);
    }
}

void inprint(node *root){
    if(root == NULL){
        return;
    }
    
    else{
        inprint(root->left);
        cout<<root->data<<" ";
        inprint(root->right);
    }
}

void postprint(node *root){
    if(root == NULL){
        return;
    }
    
    else{
        preprint(root->left);
        preprint(root->right);
        cout<<root->data<<" ";
    }
}

node* levelOrderBuild(){
    int d;
    cin>>d;
    
    queue<node*> q;
    
    node *n = new node(d);
    q.push(n);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        
        cout<<"Enter the children of "<<temp->data<<endl;
        int d1,d2;
        cin>>d1>>d2;
        
        if(d1!=-1){
            node *temp1 = new node(d1);
            temp->left = temp1;
            q.push(temp1);
        }
        
        if(d2!=-1){
            node *temp2 = new node(d2);
            temp->right = temp2;
            q.push(temp2);
        }
    }
    return n;
}

int height(node *&root){
    if(root == NULL){
        return 0;
    }
    
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    return max(h1,h2) + 1;
}

int replacenode(node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int temp = root->data;
    int left = replacenode(root->left);
    int right = replacenode(root->right);
    root->data = left + right;
    
    return temp + root->data;
}

void levelOrderPrint(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            
            cout<<temp->data<<" ";
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    
    return max(op1,max(op2,op3));
}

class Pair{
	int diameter;
	int height;
};

Pair fastdiameter(noe *root){
	Pair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}
	
	Pair left = fastdiameter(root->left);
	Pair right = fastdiameter(root->right);
	
	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;
	
	p.diameter = max(op1,max(op2,op3));
	p.height = 1 + max(left.height,right.height);
	
	return p;
}

void mirror(node *root){
    if(root==NULL){
        return;
    }
    
    mirror(root->left);
    mirror(root->right);
    
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

bool identical(node *root1, node *root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    
    if(root1!=NULL&&root2!=NULL){
        if(root1->data==root2->data&&identical(root1->left,root2->left)&&identical(root1->right,root2->right)){
            return true;
        }
        
    }
    
    return false;
}

bool ancestors(node *root, int target){
    if(root==NULL){
        return false;
    }
    
    if(root->data==target){
        return true;
    }
    
    if(ancestors(root->left,target)||ancestors(root->right,target)){
        cout<<root->data<<" ";
        return true;
    }
    
    return false;
}

node* lca(node *root, node *n1, node *n2){
    if(root==NULL){
        return NULL;
    }
    if(root==n1 || root==n2){
        return root;
    }
    
    node *left = lca(root->left,n1,n2);
    node *right = lca(root->right,n1,n2);
    
    if(left && right){
        return root;
    }
    if(left){
        return left;
    }
    return right;
}

void rightview(node *root, int level, int &maxlevel){
	if(root==NULL){
		return;
	}
	
	if(level>maxlevel){
		cout<<root->data<<endl;
		maxlevel = level;
	}
	
	rightview(root->right,level+1,maxlevel);
	rightview(root->left,level+1,maxlevel);
}

void rightviewqueue(node *root){
	queue<node *> q;
	q.push(root);
	
	while(!q.empty()){
		int n = q.size();
		for(int i=1;i<=n;i++){
			node* temp = q.front();
			q.pop();
			
			if(i==n){
				cout<<temp->data;
			}
			if(root->left){
				q.push(root->left);
			}
			if(root->right){
				q.push(root->right);
			}
		}
	}
}

void leftview(node *root, int level, int &maxlevel){
	if(root==NULL){
		return;
	}
	
	if(level>maxlevel){
		cout<<root->data<<endl;
		maxlevel = level;
	}
	
	rightview(root->left,level+1,maxlevel);
	rightview(root->right,level+1,maxlevel);
}

istream& operator>>(istream &is, node *&root){
    root = levelOrderBuild();
    return is;
}

ostream& operator<<(ostream &os, node *&root){
    preprint(root);
    return os;
}

int main() {
    
    node *root = NULL;
    node *root1 = NULL;
    cin>>root;
    cin>>root1;
    /*cout<<root<<endl;
    cout<<height(root)<<endl;
    
    //replacenode(root);
    
    cout<<root<<endl;
    
    levelOrderPrint(root);
    
    //cout<<diameter(root);
    mirror(root);*/
    levelOrderPrint(root);
    levelOrderPrint(root1);
    
    if(identical(root,root1)){
        cout<<"identical";
    }
    else{
        cout<<"nope";
    }
    
    //ancestors(root,4);
    
    cout<<lca(root,root->left->left,root->left->right)->data;
    
    return 0;
}
