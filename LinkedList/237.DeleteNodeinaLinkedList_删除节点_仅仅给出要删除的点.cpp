//
// Created by zhao on 19-4-22.
//

#include <iostream>
using  namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        ListNode* de =  node->next;
        node->next=node->next->next;
        delete(de);

    }
};



