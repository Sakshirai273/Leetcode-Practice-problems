//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    void print(Node* temp){
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    Node* findMid(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        Node* temp=new Node(0);
        Node* root=temp;
        while(left && right){
            if(left->data < right->data){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        while(left){
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right){
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        return root->next;
    }
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node* mid=findMid(head);
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        return merge(left,right);
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        head1=mergeSort(head1);
        head2=mergeSort(head2);
        //now lets union two linkedlist using some changes in merge function
        Node* left=head1;
        Node* right=head2;
        Node* temp=new Node(0);
        Node* root=temp;
        while(left && right){
            if(left->data<=temp->data) left=left->next;
            else if(right->data<=temp->data) right=right->next;
            else if(left->data==right->data) left=left->next;
            else if(left->data<right->data){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else if(right->data< left->data){
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        while(left){
            if(left->data<=temp->data) left=left->next;
            else{
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
        }
        while(right){
            if(right->data<=temp->data) right=right->next;
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        temp->next=NULL;
        return root->next;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends