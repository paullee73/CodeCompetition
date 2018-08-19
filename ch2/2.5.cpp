/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *more = new ListNode(0);
        ListNode *sol = more;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            more->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            more = more->next;
        }
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL)
            {
                sum = l1->val + carry;
                if (sum > 9)
                {
                    carry = 1;
                    sum = sum % 10;
                }
                else
                {
                    carry = 0;
                }
                more->next = new ListNode(sum);
                l1 = l1->next;
            }
            else
            {
                sum = l2->val + carry;
                if (sum > 9)
                {
                    carry = 1;
                    sum = sum % 10;
                }
                else
                {
                    carry = 0;
                }
                more->next = new ListNode(sum);
                l2 = l2->next;
            }
            more = more->next;
        }
        if (carry != 0)
        {
            more->next = new ListNode(1);
        }
        return sol->next;
    }
}; /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *more = new ListNode(0);
        ListNode *sol = more;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            more->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            more = more->next;
        }
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL)
            {
                sum = l1->val + carry;
                if (sum > 9)
                {
                    carry = 1;
                    sum = sum % 10;
                }
                else
                {
                    carry = 0;
                }
                more->next = new ListNode(sum);
                l1 = l1->next;
            }
            else
            {
                sum = l2->val + carry;
                if (sum > 9)
                {
                    carry = 1;
                    sum = sum % 10;
                }
                else
                {
                    carry = 0;
                }
                more->next = new ListNode(sum);
                l2 = l2->next;
            }
            more = more->next;
        }
        if (carry != 0)
        {
