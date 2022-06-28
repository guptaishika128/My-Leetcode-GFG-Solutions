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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = head;
        
        while(newHead && newHead->next){
            if(newHead->val == newHead->next->val){
                ListNode* temp = newHead->next;
                newHead->next = newHead->next->next;
                delete temp;
            } else{
                newHead = newHead->next;
            }
        }
        return head;
    }
};