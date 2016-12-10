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

	if (l1 == NULL)
	{
		return l2;
	}
	else if (l2 == NULL)
	{
		return l1;
	}

	int carry = 0;
	int tempval = l1->val + l2->val;
	if (tempval >= 10)
	{
		carry = 1;
		tempval -= 10;
	}
		
	ListNode * tempnext = new ListNode(tempval);
	ListNode * retval = tempnext;
	ListNode * l1ptr = l1->next;
	ListNode * l2ptr = l2->next;
	

	while (l1ptr != NULL || l2ptr != NULL)
	{
		//value to add the two numbers
		int addnum = 0;

		//get current placenumber
		if (l1ptr == NULL)
		{
			addnum = 0 + l2ptr->val + carry;
		}
		else if (l2ptr == NULL)
		{
			addnum = l1ptr->val + 0 + carry;
		}
		else
		{
			addnum = l1ptr->val + l2ptr->val + carry;
		}

		//reset carry
		carry = 0;

		//if current place numbers add up to 10 or more
		if (addnum >= 10)
		{
			//set carry and subtract 10 from current number
			carry++;
			addnum -= 10;
		}

		//set current number into listnode
		tempnext->next = new ListNode(addnum);


		//move pointers
		if (l1ptr != NULL)
		{
			l1ptr = l1ptr->next;
		}
		if (l2ptr != NULL)
		{
			l2ptr = l2ptr->next;
		}
		tempnext = tempnext->next;
	}

	if (carry)
	{
		tempnext->next = new ListNode(carry);
		carry = 0;
	}

	return retval;
}
};
