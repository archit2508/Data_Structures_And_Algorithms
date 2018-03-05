#include <iostream>
using namespace std;

class node{
public:
    int d;
    node *next;
public:
    node(int data){
        d = data;
        next = NULL;
    }
};

void print(node *head){
    while(head!=NULL){
        cout<<head->d<<"->";
        head = head->next;
    }
}

void insertAtHead(node *&head, int data){
    node *n = new node(data);
    n->next = head;
    head = n;
}

void insertInMiddle(node *&head, int dd, int position){
    if(position==0){
        insertAtHead(head,dd);
    }
    else{
        int j=1;
        node *temp = head;
        while(j<=position-1){
            temp = temp->next;
            j++;
        }
        node *n = new node(dd);
        n->next = temp->next;
        temp->next = n;
    }
}

node* midPoint(node *head){
    node *slow = head;
    node *fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

void reverse(node *&head){
    node *prev = NULL;
    node *curr = head;
    node *next;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    
    head = prev;
}

node* merge(node *a, node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    
    node *newHead;
    
    if(a->d<b->d){
        newHead = a;
        a->next = merge(a->next,b);
    }
    else{
        newHead = b;
        b->next = merge(a,b->next);
    }
    
    return newHead;
}

node* mergesort(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node *a = head;
    node *mid = midPoint(head);
    node *b = mid->next;
    mid->next = NULL;
    
    a = mergesort(a);
    b = mergesort(b);
    
    return merge(a,b);
}

void bubblesort(node *&head){
    int length=0;
    node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    
    for(int i=0;i<length-1;i++){
        node *prev = NULL;
        node *current = head;
        node *n;
        
        while(current!=NULL && current->next!=NULL){
            if(current->d<current->next->d){
                if(prev==NULL){
                    n = current->next;
                    current->next = n->next;
                    n->next = current;
                    
                    head = n;
                    prev = n;
                }
                else{
                    n = current->next;
                    current->next = n->next;
                    prev->next = n;
                    n->next = current;
                    prev = n;
                }
            }
            else{
                prev = current;
                current = current->next;
            }
        }
    }
}

node* recreverse(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node *chotahead = recreverse(head->next);
    node *temp = chotahead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return chotahead;
}

istream& operator>>(istream &obj, node *&head){
    int dd;
    cin>>dd;
    while(dd!=-1){
        insertAtHead(head,dd);
        cin>>dd;
    }
    return obj;
}

ostream& operator<<(ostream &obj, node *&head){
    print(head);
    cout<<endl;
    return obj;
}

int main() {
    
    node *head = NULL;
    
    cin>>head;
    cout<<head;
    
    insertInMiddle(head,12,3);

    cout<<head;
    
    node *temp = midPoint(head);
    
    cout<<temp->d<<endl;
    
    reverse(head);
    
    cout<<head;
    
    bubblesort(head);
    
    cout<<head;
    
    head = recreverse(head);
    
    cout<<head;
    
    return 0;
}
