/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //STEP - 1
      Node* iter=head;
      Node* front=head;
        while(iter!=NULL){
          front=iter->next;
          Node* copy = new Node(iter->val);
          iter->next=copy;
          copy->next=front;
          iter=front;
        }
        
        //STEP - 2 
        iter=head;
  while(iter!=NULL){
        if(iter->random!=NULL){
           iter->next->random=iter->random->next;
         }
    iter=iter->next->next;
        }
         iter=head;
        //STEP - 3
          Node* pseudohead=new Node(0);
          Node* copy=pseudohead;
        while(iter!=NULL){
            front=iter->next->next;
            copy->next=iter->next;
            iter->next=front;
            copy=copy->next;
            iter=front;
          }
        return pseudohead->next;
    }
};