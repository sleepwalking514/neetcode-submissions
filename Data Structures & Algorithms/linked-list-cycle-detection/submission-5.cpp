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
    bool hasCycle(ListNode* head) {
        // Faster and slower ptrs
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            // Move two ptrs
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }

        return false;
    }
};
