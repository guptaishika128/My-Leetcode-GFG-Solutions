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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL){
            if(curr->val==val){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
        
        /*
        while(cur){
            
            // If the next of cur node is to be deleted
            // then point the next pointer of cur node to the next pointer
            // of the node that has to be deleted i.e. the next of (next of cur)
            if(cur->next && cur->next->val == val)
                cur->next = cur->next->next;
            
            // If next of cur is save and should not be deleted then move cur pointer to it
            // Because we want that till cur pointer we have the nodes that need not be deleted
            else cur = cur->next;
            
        }
        */
    }
};