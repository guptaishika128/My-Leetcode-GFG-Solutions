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
    
    int length(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre = dummy , *curr , *nex;
        
        int len = length(head);
        while(len>=k){
            curr = pre->next;
            nex = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            len -= k;
        }
        return dummy->next;
    }
};