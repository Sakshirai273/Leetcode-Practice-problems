//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void countnodes(struct Node* root,int &count){
    if(root==NULL) return;
    count++;
    countnodes(root->left,count);
    countnodes(root->right,count);
    return ;
}
int findg(Node* root){
    if(root==NULL) return INT_MIN;
    while(root->right) root=root->right;
    return root->data;
}
int findl(struct Node* root){
    while(root->left)root=root->left;
    return root->data;
}
// float inorder(Node* root,int )
float findm(struct Node* root,int c,int median,int m2){
    int count=0;
    countnodes(root->left,count);
    if(median==m2){
        if(count+1+c==median) return root->data;
        else if(count+1+c<median){
            root=root->right;
            return findm(root,count+1+c,median,m2);
            
        }
        else if(count+1+c>median){
            root=root->left;
        return findm(root,c,median,m2);
        }
    }
    else{
        if(count+1+c==median){
            int fl=findl(root->right);
            float ans=(root->data+fl)/2.0;
            return ans;
        }
        else if(count+1+c==m2){
            int fg=findg(root->left);
            float ans=(root->data+fg)/2.0;
            return ans;
        }
        else if(count+1+c<median){
            root=root->right;
            return findm(root,count+1+c,median,m2);
        }
        else if(count+1+c>median){
            root=root->left;
            return findm(root,c,median,m2);
        }
        else {
            root=root->right;
            return findm(root,count+c+1,median,m2);
        }
    }
}
float findMedian(struct Node *root)
{
    int med=0;
    countnodes(root,med);
    int m1=0;
    int m2=0;
    if(med%2==0) {
        m1=med/2;
        m2=med/2 + 1;
    }
    else{
        m1=(med+1)/2;
        m2=m1;
    }
    float ans=findm(root,0,m1,m2);
    return ans;
}