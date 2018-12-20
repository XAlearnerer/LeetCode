//
// Created by zhao on 18-12-1.
//

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)  return head;
        ListNode *dummy=new ListNode(-1);
        ListNode *newdummy=new ListNode(-1);
        dummy->next=head;
        ListNode *oPre=dummy;
        ListNode *newPre=newdummy;
        while(oPre->next)
        {
            if(oPre->next->val < x)
            {
                newPre->next=oPre->next;
                newPre=newPre->next;
                oPre->next=oPre->next->next;
                newPre->next=NULL;
            }
            else
                oPre=oPre->next;
        }

        newPre->next=dummy->next;
        return newdummy->next;
    }
};