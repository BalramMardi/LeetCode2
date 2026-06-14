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
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid =slow;

        ListNode* prev =NULL;
        ListNode* nextNode = NULL;

        while(mid){
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        int result= 0;

        ListNode* curr = head;

        while(prev){

            result = max( result , prev->val + curr->val);
            prev= prev->next;
            curr = curr->next;
        }

        return result;

        
    }
};