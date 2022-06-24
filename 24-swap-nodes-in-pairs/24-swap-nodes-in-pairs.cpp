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
        if(head == NULL || head->next==NULL){
            return head;
        }
   /*     
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
    */
      // there is only one node in list
  
    // Initialize previous and current pointers
ListNode*prev= head;
ListNode*curr = head->next;
  
    head = curr; // Change head before proceeding
  
    // Traverse the list
    while (true) {
    ListNode*next = curr->next;
        curr->next = prev; // Change next of
        // current as previous node
  
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
  
        // Change next of previous to next of next
        prev->next = next->next;
  
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
    return head;   

    }
};