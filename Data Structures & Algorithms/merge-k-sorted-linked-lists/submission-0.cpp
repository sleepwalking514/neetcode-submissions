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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* ptr = &dummy;

        std::priority_queue<pair<int, int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            // Push negative val => min heap
            pq.push({-lists[i]->val, i});
        }

        // Until all lists are exhausted
        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();
            // Add to chain
            ptr->next = lists[index];
            ptr = ptr->next;
            if ((lists[index] = lists[index]->next) != nullptr) {
                pq.push({-lists[index]->val, index});
            }
        }

        return dummy.next;
    }
};
