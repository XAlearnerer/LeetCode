#include<iostream>
#include<stack>
using namespace std;


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		t.push(x);
		if (mn.empty()) mn.push(x);
		else
		{
			if (mn.top() < x) mn.push(mn.top());
			else mn.push(x);
		}
	}

	void pop() {
		mn.pop();
		t.pop();
	}

	int top() {
		return t.top();
	}

	int getMin() {
		return mn.top();
	}

	stack<int> t;
	stack<int> mn;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/
