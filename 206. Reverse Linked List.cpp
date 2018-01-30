// https://leetcode.com/problems/reverse-linked-list/description/

// Reverse a singly linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// iterative version 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        
        ListNode* cur = head->next;
        head->next = nullptr;
        ListNode* tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = head;
            head = cur;
            cur = tmp;
        }
        return head;
    }
};

// recursive version
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        return helper(head).first;
    }
    
private:
    // head != nullptr
	// return: {head, tail}
    pair<ListNode*, ListNode*> helper(ListNode* head) {
        if (!head->next)
            return {head, head};
        
        auto head_tail = helper(head->next);
        head_tail.second->next = head;
        head->next = nullptr;
        return {head_tail.first, head};
    }
};