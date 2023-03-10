// Approach 1(Using Linked List)

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
int len=0;
ListNode* temp;
ListNode*headNode;
    Solution(ListNode* head) {
        headNode=head;
        temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
    }
    
    int getRandom() {
        int random_index = rand()%len;
        ListNode* temp = headNode;
        for(int i=0;i<random_index;i++)
        {
            temp=temp->next;
        }
        return temp->val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */


// Approach 2(Using Vector)

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
vector<int>nums;ListNode *temp;
    Solution(ListNode* head) {
       
        temp=head;
        while(temp!=NULL)
        {int num=temp->val;
             temp=temp->next;
           nums.push_back(num);
        }
        
    }
    
    int getRandom() {
      random_shuffle(nums.begin(),nums.end());return nums[0];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
