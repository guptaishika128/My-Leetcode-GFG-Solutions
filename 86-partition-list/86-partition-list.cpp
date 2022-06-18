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
    ListNode* partition(ListNode* head, int x) {
         ListNode *greaterHead = NULL;
         ListNode *greaterLast = NULL;
         ListNode *smallerHead = NULL;
         ListNode *smallerLast = NULL;
  
  while(head!=NULL){
      
      if(head->val>=x){
          if(greaterHead == NULL){
              greaterHead = greaterLast = head;
          } else{
              greaterLast->next = head;
              greaterLast = greaterLast->next;
          }
      }
      
      if(head->val<x){
          if(smallerHead == NULL){
              smallerHead = smallerLast = head;
          }
          else{
              smallerLast->next = head;
              smallerLast = smallerLast->next;
          }
      }
      head=head->next;
  }
  
  if(greaterLast!=NULL){
      greaterLast->next = NULL;
  }
  
  // If list containing smaller elemnts than x is empty
  if(smallerHead == NULL){
      return greaterHead;
  }
  
  // If list containing greater or equal elements is empty
  if(greaterHead == NULL){
      smallerLast->next= NULL;
      return smallerHead;
  }
  
  // If both lists are not empty
  smallerLast->next = greaterHead;
  return smallerHead;
    }
};