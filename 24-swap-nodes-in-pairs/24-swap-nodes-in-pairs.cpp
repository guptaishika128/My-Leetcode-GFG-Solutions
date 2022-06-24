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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        // Store head of list after two nodes
    ListNode* remaining = head->next->next;
 
    // Change head
    ListNode* newhead = head->next;
 
    // Change next of second node
    head->next->next = head;
 
    // Recur for remaining list and change next of head
    head->next = swapPairs(remaining);
 
    // Return new head of modified list
    return newhead;
    }
};