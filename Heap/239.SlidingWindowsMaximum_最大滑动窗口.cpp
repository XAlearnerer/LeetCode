//
// Created by zhao on 19-4-9.
//

#include <iostream>
#include <vector>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;


// Could you solve it in linear time?

//����������һ�����飬������һ�����ڴ�Сk��������ÿ�����һ���һ�����֣�
//ÿ�η��ش����ڵ����ֵ����ֵ������Ҫ�����Ǵ����ʱ�临�Ӷ�ΪO(n)��
//��ʾ����Ҫ��˫�����deque�����⣬����ʾ���Ǵ�����ֻ�������õ�ֵ��û�õ�ȫ�Ƴ�����
//
//���˼·����˫����б������ֵ��±꣬�����������飬�����ʱ���е���Ԫ����i - k�Ļ���
//��ʾ��ʱ������������һ�������Ƴ�����Ԫ�ء�Ȼ��Ƚ϶�βԪ�غͽ�Ҫ������ֵ��
//���С�Ļ��Ͷ��Ƴ���Ȼ���ʱ���ǰѶ���Ԫ�ؼ������м��ɣ�

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> d;

    }
};


class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> q;
		for (int i = 0; i < nums.size(); ++i) {
			if (!q.empty() && q.front() == i - k) q.pop_front();
			while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
			q.push_back(i);
			if (i >= k - 1) res.push_back(nums[q.front()]);
		}
		return res;
	}
};

class Solution3 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int size = nums.size();
		vector<int> ans;
		if (size == 0) return nums;
		for (int i = 0; i < 1 + size - k; i++) {
			int temp = INT_MIN;
			for (int j = i; j < i + k; j++) {
				temp = max(temp, nums[j]);
			}
			ans.push_back(temp);
		}
		return ans;
	}
};


