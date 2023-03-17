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
    int pairSum(ListNode* head) {
        ListNode* temp=head;

        int count=0;
stack<int>s;
        while(temp!=NULL ){
            count++;
               s.push(temp->val);
               temp=temp->next;
        }

        temp=head;
stack<int>maxi;
        for(int i=0;i<(count/2);i++)
        {
            int sum=temp->val+s.top();
          cout<<s.top()<<" ";
            temp=temp->next;
            s.pop();
         if(!maxi.empty() && sum>=maxi.top())
         {
             maxi.push(sum);
         }
         if(maxi.empty())
         {
             maxi.push(sum);
         }
        

        }
        return maxi.top();
      
        
        
    }
};
