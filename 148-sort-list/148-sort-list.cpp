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
    
    ListNode* merge(ListNode* L , ListNode* R){
        if(!L){
            return R;
        }
        if(!R){
            return L;
        }
        
        ListNode* newhead = NULL;
        
        if(L->val<R->val){
            newhead = L;
            newhead->next = merge(L->next,R);
        } else{
            newhead = R;
            newhead->next = merge(L,R->next);
        }
        return newhead;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode *slow = head, *fast = head->next; 
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *left = head, *right = slow->next;
    slow->next = NULL;
        
      
        
        left = sortList(left);
        right = sortList(right);
        
        return merge(left,right);
    }
};