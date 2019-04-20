#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//������ǿ���ָ��ľ���Ӧ�á�
//ֻ��Ҫ������ָ�룬һ��ÿ����һ������ָ���һ��ÿ���������Ŀ�ָ�룬
//����������л��Ļ�������ָ�����տ϶���������ʵ����̫�����ˡ�

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fast = head,* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

