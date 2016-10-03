#pragma once
#include "Solution.h"

class AddTwoNumbers : public Solution
{
private:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int r = 0;
		return addTwoNumbers(l1, l2, r);
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int r)
	{
		if (l1 == nullptr && l2 == nullptr && r == 0)
		{
			return nullptr;
		}
		ListNode* result = new ListNode(0);

		int value = r;

		if (l1 != nullptr)
		{
			value += l1->val;
		}
		if (l2 != nullptr)
		{
			value += l2->val;
		}

		result->val += value % 10;

		if (l1 || l2)
		{
			ListNode* more = addTwoNumbers(l1 == nullptr ? l1 : l1->next, l2 == nullptr ? l2 : l2->next, value >= 10 ? 1 : 0);

			result->next = more;

		}

		return result;
	}

public:
	void Test()
	{
		ListNode l1(1);
		ListNode l12(4);
		ListNode l13(9);
		l1.next = &l12; l12.next = &l13;

		ListNode l2(8);
		ListNode l22(7);
		ListNode l23(6);
		l2.next = &l22; l22.next = &l23;

		cout << "Add two list number solution for [" << &l1 << "] and [" << &l2 << "]: " <<  addTwoNumbers(&l1, &l2) << endl;
	}

};