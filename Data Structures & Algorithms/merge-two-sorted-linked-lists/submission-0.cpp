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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* ptr = &dummy;

        while (list1 || list2) {
            int n1 = list1 ? list1->val : 128; // Something greater than bound
            int n2 = list2 ? list2->val : 128;

            if (n1 <= n2) {
                ListNode* temp = list1;
                list1 = list1->next;
                ptr->next = temp;
            } else {
                ListNode* temp = list2;
                list2 = list2->next;
                ptr->next = temp;
            }
            ptr = ptr->next;
            ptr->next = nullptr;
        }

        return dummy.next;
    }
};
