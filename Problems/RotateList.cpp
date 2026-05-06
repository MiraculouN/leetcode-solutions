/*
 * @lc app=leetcode id=1995783610 lang=cpp
 *
 * RotateList
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        deque<ListNode*>dq;
        while(head!=NULL){
            dq.push_back(head);
            head = head->next;
        }
        int n = dq.size();
        k%=n;
        while(k--){
            ListNode * l = dq.back();
            dq.pop_back();
            dq.back()->next = NULL;
            l ->next = dq.front();
            dq.push_front(l);

        }
        return dq.front();

    }
};