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

        ListNode *  temp = head;
        
        if(temp == NULL) return temp;
        if(temp->next == NULL) return temp;

        while(temp->next !=NULL)
        {
            swap(temp->val,temp->next->val);
            if(temp->next->next==NULL){
            break;
            }
            temp = temp->next->next;
        }

        return head;
        
    }
};
