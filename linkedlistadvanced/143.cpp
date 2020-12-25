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
 /*
        if(!head){
            return;
        } //if head is null, return.
        
        // 1.find the mid
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        
        //2.second, reverse the second half list
        ListNode *newhead = reverse(mid);
        
        //3.connect two linked list
        while(head->next != NULL && newhead -> next != NULL){
            ListNode *temp1 = head -> next;
            ListNode *temp2 = newhead -> next;
            head -> next = newhead;
            newhead -> next = temp1;
            head = temp1;
            newhead = temp2;
        }
    }
    */
        
/*
public:
    ListNode* reverse(ListNode *head){
        if(!head->next){
            return head;
        }
        
        ListNode* pre = nullptr;
        while(head){
            ListNode* next = head->next;
            head -> next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }*/
        
        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *last = mid, *pre = NULL;
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};
