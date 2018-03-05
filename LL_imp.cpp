#include <bits/stdc++.h>
using namespace std;

class node{
    int data;
    node *next;
    
public
    node(int d){
        data = d;
        next = NULL;
    }
}

void insertAtHead(node *&head, int d){
    node *n = new node(d);
    n->next = head;
    head = n;
}

void insertInMiddle(node *&head, int d, int p){
    node *n = new node(d);
    int j=1;
    node *temp = head;
    while(j<=p-1){
        temp = temp->next;
        j++;
    }
    
    n->next = temp->next;
    temp->next = n;
}

node* midPoint(node *head){
    node *slow = head;
    node *fast = head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void reverse(node *&head){
    node *prev = NULL;
    node *current = head;
    node *n;
    
    while(current!=NULL){
        n = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

node *recreverse(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node *chhotahead = recreverse(head->next);
    node *temp = chhotahead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    
    return chhotahead;
}

node *recReverse(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node *chhotahead = recreverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return chhotahead;
}

void duplicates(node *head){
    node *prev = NULL;
    node *curr = head;
    
    unordered_set<int> s;
    while(curr!=NULL){
        if(s.find(curr->data)!=s.end()){
            prev->next = curr->next;
            delete(curr);
        }
        else{
            s.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int plusone(node *head){
	if(head == NULL){
		return 1;
	}
	
	int m = plusone(head->next);
	int res = root->data + m;
	root->data = res%10;
	
	return res/10;
}

node *merge(node *a, node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    
    if(a->data<b->data){
        node *newHead = a;
        a->next = merge(a->next,b);
    }
    if(b->data<a->data){
        node *newHead = b;
        b->next = merge(b->next,a);
    }
    
    return newHead;
}

node *mergesort(node *head){
    if(head == NULL && head->next == NULL){
        return head;
    }
    
    node *a = head;
    node *mid = midPoint(head);
    node *b = mid->next;
    
    a = mergesort(head);
    b = mergesort(temp);
    
    return merge(a,b);
}

int main() {
    return 0;
}
