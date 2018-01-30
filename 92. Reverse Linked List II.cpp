// https://leetcode.com/problems/reverse-linked-list-ii/description/

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode tmp_node(0);
        ListNode* header = &tmp_node;
        header->next = head;
        
        ListNode* prev = header;
        ListNode* p = head;
        for (int i = 1; i < m; ++i) {
            prev = p;
            p = p->next;
        }
        prev->next = reverse(p, n-m+1);
        
        return header->next;
    }
    
private:
    ListNode* reverse(ListNode* head, int count) {        
        ListNode* tail = head;
        ListNode* cur = head->next;
        ListNode* tmp = nullptr;
        
        while (--count) {
            tmp = cur->next;
            cur->next = head;
            head = cur;
            cur = tmp;
        }
        tail->next = cur;
        
        return head;
    }
};