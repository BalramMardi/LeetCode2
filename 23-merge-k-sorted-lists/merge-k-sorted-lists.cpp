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
    typedef pair<int,ListNode*> pp;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pp,vector<pp>,greater<pp>> pq; //val,row,col
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (auto list : lists) {
            if (list) pq.push({list->val, list});
        }

        vector<int> ans;

        while(pq.size()){
            auto [currval, node] = pq.top();
            pq.pop();
            
            tail->next = node;  
            tail = tail->next;

             if (node->next) {
                pq.push({node->next->val, node->next});
            }

        }

        return dummy->next;
    }
};