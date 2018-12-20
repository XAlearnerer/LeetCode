//
// Created by zhao on 18-11-15.
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using  namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return {};
		//int ls = lists.size();
		int i = 0;
		while (i < lists.size())
        {
			if (lists[i] == NULL) {
				lists.erase(find(lists.begin(), lists.end(), lists[i]));
			}
			else
				++i;
        }
		if (lists.empty()) return {};


        ListNode* cur=new ListNode(-1);
        ListNode* b=cur;
        while(!lists.empty())
        {
            if(lists.size()==1) cur->next=lists[0];
            int mini=-1,minval=INT_MAX;
            for(int i=0;i!=lists.size();++i)
            {
				if (lists[i]->val < minval)
                {
                    minval=lists[i]->val;
                    mini=i;
                }
            }
            cur->next=lists[mini];
            cur=cur->next;
            if(!lists[mini]->next)
            {
                lists.erase(find(lists.begin(),lists.end(),lists[mini]));
            }
            else
                lists[mini]=lists[mini]->next;
        }
        return b->next;
    }
};

int main2026()
{
    ListNode *a=new ListNode(1);
    a->next=new ListNode(4);
    a->next->next=new ListNode(5);
    a->next->next->next=NULL;

    ListNode *b=new ListNode(1);
    b->next=new ListNode(3);
    b->next->next=new ListNode(4);
    b->next->next->next=NULL;

    ListNode *c=new ListNode(2);
    c->next=new ListNode(6);
    c->next->next=NULL;

    ListNode *d=new ListNode(1);
    d->next=NULL;

	ListNode *e = NULL;

	vector<ListNode*> lists = { d,e };
    Solution n;
    ListNode *r=n.mergeKLists(lists);

    while(r)
    {
        cout<<r->val<<" -> ";
        r=r->next;
    }
    cout<<endl;

    return 0;
}