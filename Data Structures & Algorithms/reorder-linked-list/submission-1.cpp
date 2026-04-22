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
    void reorderList(ListNode* head) {
        // Use fast and slow ptrs to find the middle node
        // Cut the chain into two from the middle and reverse the second half
        // Merge the two halfs into one
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr; // Handle the tail of the chain after merging
        ListNode* prev = nullptr;

        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode* ptr = head;
        while (ptr) {
            ListNode* tmp = ptr->next;
            ptr->next = prev;
            if (prev == nullptr) break;
            ListNode* tmp2 = prev->next;
            prev->next = tmp;
            prev = tmp2;
            ptr = tmp;
        }
    }
};
