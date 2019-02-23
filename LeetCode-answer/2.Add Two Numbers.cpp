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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pRet = new ListNode(0);
		ListNode *p = pRet;

		int carry(0), now;
		bool first = true;

		while (l1 || l2 || carry) {
			now = carry;
			if (l1) now += l1->val;
			if (l2) now += l2->val;

			carry = (int)(now >= 10);
			now %= 10;

			if (first)
			{
				first = false;
				p->val = now;
			}
			else
			{
				p->next = new ListNode(now);
				p = p->next;
			}
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		};
		return pRet;

    }
};
