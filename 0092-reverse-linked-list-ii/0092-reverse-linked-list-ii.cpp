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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (l > 1) {
            prev = curr;
            curr = curr->next;
            l--;
            r--;
        }

        ListNode* connect = prev;
        ListNode* end = curr;
        ListNode* temp;

        while (r > 0) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            r--;
        }

        if (connect) {
            connect->next = prev;
        } else {
            head = prev;
        }

        end->next = curr;
        return head;
    }
};
