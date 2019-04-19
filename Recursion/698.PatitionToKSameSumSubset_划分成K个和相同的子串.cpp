#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



//  ������������һ������nums��һ������k�������Ǹ������ܲ��ֳܷ�k���ǿ��Ӽ��ϣ�
//  ʹ��ÿ���Ӽ��ϵĺ���ͬ������k�ķ�Χ��[1, 16]��
//  ���������е����ֶ������������֮ǰ�ǵ� Partition Equal Subset Sum �����ƣ�
//  �����ǵ���ֻ�÷ֳ������Ӽ��ϣ������������ת��Ϊ�Ƿ���ں�Ϊ��������͵�һ����Ӽ��ϣ�
//  ������dp������

//  �������������k������ͬ�ģ��о��޷���dp��������Ϊ�����ҳ���һ����
//  �����Ҳ��Ҫ��֤����������ǿ����õݹ��������������ǻ�������������������֮��sum��
//  �����ж�sum�Ƿ�������k�����������Ļ�ֱ�ӷ���false��
//  Ȼ����Ҫһ��visited��������¼��Щ�����Ѿ���ѡ���ˣ�
//  Ȼ����õݹ麯�������ǵ�Ŀ������k���Ӽ��ϣ��ǵ�ÿ���Ӽ���֮��Ϊtarget = sum / k��
//  ���ǻ���Ҫ����start����ʾ�������ĳ��λ�ÿ�ʼ���ң�curSumΪ��ǰ�Ӽ���֮�ͣ�
//  �ڵݹ麯���У����k = 1��˵����ʱֻ��Ҫ��һ���Ӽ��ϣ���ô��ǰ�ľ����ˣ�ֱ�ӷ���true��
//  ���curSum����target�ˣ���ô�����ٴε��õݹ飬��ʱ����k - 1��start��curSum������Ϊ0��
//  ��Ϊ���ǵ�ǰ���ҵ���һ����Ϊtarget���Ӽ��ϣ�Ҫ��ʼ��������һ����
//  ����Ļ��ʹ�start��ʼ�������飬�����ǰ�����Ѿ����ʹ�����ֱ��������
//  ������Ϊ�ѷ��ʡ�Ȼ����õݹ麯����k���ֲ��䣬��Ϊ�����ۼӵ�ǰ���Ӽ��ϣ�
//  start����i + 1��curSum����curSum + nums[i]����ΪҪ�ۼӵ�ǰ�����֣�
//  ����ݹ麯������true�ˣ���ֱ�ӷ���true������ͽ���ǰ��������Ϊδ���ʵ�״̬����������



class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		for (auto i : nums)
			sum += i;
		if (sum%k != 0) return false;
		vector<int> visited(nums.size(), 0);
		int target = sum / k;
		return helper(nums, visited, target, 0, k, 0);
	}

	bool helper(vector<int>& nums, vector<int>& visited,int target,int start,int k,int cur)
	{
		if (k == 1) return true;
		if (cur == target) return helper(nums, visited, target, 0, k - 1, 0);
		for (int i = start; i != nums.size(); ++i)
		{
			if (visited[i]) continue;
			visited[i] = 1;
			if (helper(nums, visited, target, i, k, cur + nums[i])) return true;
			visited[i] = 0;
		}
		return false;
	}
};


//����Ҳ���Զ�����Ľⷨ����һЩ�Ż��������ȸ����鰴�Ӵ�С��˳���Ÿ���
//Ȼ���ڵݹ麯���У����ǿ���ֱ���жϣ����curSum����target�ˣ�ֱ�ӷ���false��
//��Ϊ��Ŀ���޶��˶�����������������Ҳ�����������ˣ����������ֻ�ܸ���
//�����֦������������������ٶ�


class Solution { //����������������������sort����
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (auto i : nums)
			sum += i;
		if (sum%k != 0) return false;
		int target = sum / k;
		vector<int> visited(nums.size(), 0);
		return helper(nums, visited, target, 0, k, 0);
	}

	bool helper(vector<int>& nums, vector<int>& visited, int target, int start, int k, int cur)
	{
		if (k == 1) return true;
		if (cur > target) return false;
		if (cur == target) return helper(nums, visited, target, 0, k - 1, 0);
		for (int i = start; i != nums.size(); ++i)
		{
			//if (nums[i] > target - cur) break;
			if (visited[i] == 1) continue;
			visited[i] = 1;
			if (helper(nums, visited, target, i, k, cur + nums[i])) return true;
			visited[i] = 0;
		}
		return false;
	}

};





