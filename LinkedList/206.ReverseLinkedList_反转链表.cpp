//
// Created by zhao on 19-4-22.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newnode=NULL;
        while(head)
        {
            ListNode* cur=head->next;
            head->next=newnode;
            newnode=head;
            head=cur;
        }

        return newnode;
    }
};

