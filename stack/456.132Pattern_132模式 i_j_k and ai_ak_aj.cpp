#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution2 {
public:
	/*bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3) return false;
		stack<int> s;
		s.push(nums[0]);
		bool up = false;
		bool down = false;
		
		for (int i = 1; i != nums.size(); ++i)
		{
			if (s.top() < nums[i])
			{
				s.push(nums[i]);
				up = true;
			}
			else if (s.top() > nums[i])
			{
				if (up == true) return true;
				s.pop();
				s.push(nums[i]);
			}
			else
				continue;
		}
		return false;
	}*/


	bool find132pattern(vector<int>& nums) {
		stack<int> s;
		int cur = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] < cur) return true;
			else
			{
				while (!s.empty() && nums[i] > s.top())
				{
					cur = s.top();
					s.pop();
				}
			}
			s.push(nums[i]);
		}
		return false;
	}

};



class Solution3 {
public:
	bool find132pattern(vector<int>& nums) {
		int i = INT_MAX;
		for (int j = 0; j != nums.size(); ++j)
		{
			i = min(i, nums[j]);
			if (i == nums[j]) continue;
			for (int k = nums.size() - 1; k > j; --k)
			{
				if (nums[j] > nums[k] && nums[k] > i)
					return true;
			}
		}
		return false;
	}
};

//˼·������ά��һ��ջ��һ������third������third���ǵ��������֣�
//Ҳ��pattern 132�е�2��ջ���水˳������д���third�����֣�
//Ҳ��pattern 132�е�3����ô�����ڱ�����ʱ�������ǰ����С��third��
//��pattern 132�е�1�ҵ��ˣ�����ֱ�ӷ���true���ɣ���Ϊ�Ѿ��ҵ��ˣ�
//ע������Ӧ�ôӺ���ǰ�������顣�����ǰ���ִ���ջ��Ԫ�أ�
//��ô���ǰ�˳��ջ������ȡ������ֵ��third��Ȼ�󽫸�����ѹ��ջ��
//������֤��ջ���Ԫ����Ȼ���Ǵ���third�ģ�������Ҫ��˳�����ɴ��ڣ�
//��һ����˵��ջ���ŵĶ��ǿ���ά��second > third��secondֵ��
//���е��κ�һ��ֵ���Ǵ��ڵ�ǰ��thirdֵ������и����ֵ������
//�Ǿ͵����γ���һ�����ŵ�second > third������һ����ϣ�
//������ʱ������thirdֵ����ǰ��thirdֵ����ΪʲôҪ��֤thirdֵ����
//��Ϊ�����ſ��Ը����׵����㵱ǰ��ֵfirst��thirdֵС���������

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		stack<int> s;
		int third = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] < third)
				return true;
			else
			{
				while (!s.empty() && s.top() < nums[i])
				{
					third = s.top();
					s.pop();
				}
			}
			s.push(nums[i]);
		}

		return false;
	}
};










