/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode* h1 = head;
//         stack<int> s1;
//         while(h1 != NULL){
//             s1.push(h1->val);
//             h1 = h1->next;
//         }
//         while(!s1.empty()){
//             if(s1.top() != head->val){
//                 return false;
//             }
//             else{
//                 s1.pop();
//                 head = head->next;
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != NULL){
            slow = slow->next;
        }
        slow = reverse(slow);
        fast = head;
        
        while(slow != NULL){
            if(fast->val != slow->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
