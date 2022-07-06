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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     /*   2 PASS 
     if(head==NULL){
            return NULL;
        }
        
        int len = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        if(len-n==0){
            return head->next;
        }
        curr = head;
        for(int i=1;i<(len-n);i++){
            curr=curr->next;
        }
        curr->next= curr->next->next;
        return head;
        
        */
        if(head==NULL){
            return NULL;
        }
        
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        
        if(!fast){
            ListNode* temp = head;
            head= head->next;
            delete temp;
            return head;
        }
        
        ListNode* slow = head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* temp2 = slow->next;
        slow->next = temp2->next;
        delete temp2;
        return head;
    }
};