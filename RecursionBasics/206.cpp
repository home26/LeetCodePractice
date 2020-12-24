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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *next = nullptr, *temp = nullptr;
        while(curr != nullptr){
            temp = curr -> next;
            curr -> next = next;
            next = curr;
            curr = temp;
        }
        return next;
    }
};
