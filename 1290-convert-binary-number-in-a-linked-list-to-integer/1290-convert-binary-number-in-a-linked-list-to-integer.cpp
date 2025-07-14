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
    int getDecimalValue(ListNode* head) {
        
        int n = 0;
        ListNode* cur=head;
        while(cur!=NULL){
            cur=cur->next;
            n++;
        }
        
        int ans = 0;
        while(head!=NULL){
            ans += (head->val)*(1<<(n-1));
            n--;
            head = head->next;
        }
        return ans;
    }
};

