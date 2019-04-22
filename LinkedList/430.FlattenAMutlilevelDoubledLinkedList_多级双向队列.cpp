#include<iostream>

using namespace std;

class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};


class Solution {
public:
	Node* flatten(Node* head) {
		if (!head) return head;
		Node* cur = head;
		while (cur)
		{
			if (cur->child)
			{
				Node* curnext = cur->next;
				cur->child = flatten(cur->child);
				Node *pre = cur->child;
				while (pre->next) pre = pre->next;

				cur->next = cur->child;
				cur->child->prev = cur;
				cur->child = NULL;

				pre->next = curnext;
				//curnext->prev = pre;
				if (curnext)
					curnext->prev = pre;
			}
			cur = cur->next;
		}
		return head;
	}
};






