//
// Created by zhao on 19-4-12.
//
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);

    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len=q.size();
        int i=0;
        int f=0;
        while(i<len)
        {
            f=q.front();
            if(i!=len-1)
                q.push(f);
            q.pop();
            ++i;
        }
        return f;
    }

    /** Get the top element. */
    int top() {
        return q.back();

    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
