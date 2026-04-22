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
        std::vector<ListNode*> nodeVec;
        while (head) {
            nodeVec.push_back(head);
            head = head->next;
        }

        ListNode dummy;
        ListNode* ptr = &dummy;
        int n = nodeVec.size();

        for (int i = 0; i <= (n - 1) / 2; i++) {
            ptr->next = nodeVec[i];
            ptr = ptr->next;
            if (i == n - i - 1) break;
            ptr->next = nodeVec[n - i - 1];
            ptr = ptr->next;
        }
        ptr->next = nullptr;

        head = dummy.next;
    }
};
