#include<iostream>

using namespace std;


class MyLinkedList2 {  //? 这样写的话 addindex 会出问题
public:
	/** Initialize your data structure here. */
	MyLinkedList2() {
		head = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		ListNode* cur = head;
		while (index--)
			cur = cur->next;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* newhead = new ListNode(val);
		newhead->next = head;
		head = newhead;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* cur = head;
		ListNode* node = new ListNode(val);
		while (cur->next)
			cur = cur->next;
		cur->next = node;
		node->next = NULL;

	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		ListNode* cur = head;
		ListNode* node = new ListNode(val);
		while(--index)
		{
			cur = cur->next;
		}
		ListNode* next = cur->next;
		cur->next = node;
		node->next = next;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
	/*	ListNode* pre = new ListNode(-1);
		pre->next = head;*/
		ListNode* cur = head;
		while (--index)
		{
			cur = cur->next;
		}
		ListNode* next = cur->next;
		if (next->next)
		{
			ListNode* nn = next->next;
			cur->next = nn;
			delete(next);
		}
		else
		{
			cur->next = NULL;
			delete(next);
		}


	}

	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	ListNode* head;
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/


