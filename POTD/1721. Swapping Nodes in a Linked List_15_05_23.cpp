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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* start =head;
        ListNode* end =head;
           

           for(int i = 0; i<k-1 ; i++){
               start =start->next;
           }

           ListNode* left =start;

           while(start->next){
               end = end->next;
               start = start->next;
           }

           swap(left->val,end->val);

           return head;

        
    }
};
