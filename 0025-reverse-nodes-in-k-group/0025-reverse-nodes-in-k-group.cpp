/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 0;
        ListNode *temp = head;
         while(temp!=NULL){
            temp = temp -> next;
             sz++;
         }
        
         if(sz < k)    return head; 
             
        // base call
        if ( head == NULL){
            return NULL;
        }
        //step 1: reverse first K nodes 
        
        ListNode* next = NULL; 
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0 ;
        

        while( curr != NULL &&  cnt < k){
            next = curr -> next ;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
          } 
        
           if(cnt < k)    
               return head;   
        
        // step 2: Recursion dekhlega aage ka
        if(next != NULL){
            head -> next = reverseKGroup (next,k);
        }
        //step 3: return head of reversed list
         return prev;
    }
};


//         ListNode *temp = head;
//         while(temp!=NULL){
//             temp = temp -> next;
//             size++;
//         }
//         if(size < k)    return head;   

//         // Base call
//         if(head == NULL)
//             return NULL;

