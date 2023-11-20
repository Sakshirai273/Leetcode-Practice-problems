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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
	    // if list1 is NULL ,we will simply return list2.
		
        if(list1 == NULL)
            return list2;
		
		// if list2 is NULL, we will simply return list1.
        if(list2 == NULL)
            return list1;
        
        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        ListNode *cur = ptr;
        
		// till one of the list doesn't reaches NULL
        while(list1 &&  list2)
        {
            if(list1 -> val < list2 -> val){
                cur->next = list1;
                list1 = list1 -> next;
            }
            else{
                cur->next = list2;
                list2 = list2 -> next;
            }
            cur = cur -> next;
                
        }
		
		// adding remaining elements of bigger list.
        if(!list1)
            cur -> next = list2;
        else
            cur -> next = list1;
            
        return ptr;
       
    }
};   
