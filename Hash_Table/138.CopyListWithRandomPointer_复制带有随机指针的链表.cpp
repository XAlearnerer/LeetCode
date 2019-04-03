//
// Created by zhao on 19-4-3.
//
#include <iostream>
#include <unordered_map>
using  namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return NULL;
        Node *res = new Node(head->val, nullptr, nullptr);
        Node *node = res;
        Node *cur = head->next;
        unordered_map<Node*,Node*> map;
        map[head]=res;
        while (cur) {
            Node *tmp = new Node(cur->val, nullptr, nullptr);
            node->next = tmp;
            map.insert(pair<Node*,Node*>(cur,tmp));
            node = node->next;
            cur = cur->next;
        }

        Node *s1=res;
        Node *s2=head;
        // random的对应关系
        while(s1)
        {
            s1->random=map[s2->random];
            s1=s1->next;
            s2=s2->next;
        }

        return res;
    }
};




