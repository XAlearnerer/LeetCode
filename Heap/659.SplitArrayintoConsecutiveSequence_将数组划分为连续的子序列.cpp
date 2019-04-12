//
// Created by zhao on 19-4-10.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,tail;
        for(int i=0;i!=nums.size();++i)
        {
            ++freq[nums[i]];
        }
        for(int n:nums)
        {
            if(tail[n-1]>0)
            {
                --tail[n-1];
                ++tail[n];
            }
            else if(tail[n-1]==0)
            {
                if(freq[n+1]>0 && freq[n+2]>0)
                {
                    ++tail[n+2];
                    --freq[n+1];
                    --freq[n];
                }
                else
                    return false;
            }
        }
        return true;
    }
};


class Solution2 {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int num : nums) ++freq[num];
        for (int num : nums) {
            if (freq[num] == 0) continue;
            else if (need[num] > 0) {
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else return false;
            --freq[num];
        }
        return true;
    }
};


//注意这里可能会产生歧义，实际上应该是分割成一个或多个连续递增的子序列，
//因为[1,2,3,4,5]也是正确的解。这道题就用贪婪解法就可以了，
//我们使用两个哈希表map，第一个map用来建立数字和其出现次数之间的映射freq，
//第二个用来建立可以加在某个连续子序列后的数字及其可以出现的次数之间的映射need。
//对于第二个map，举个例子来说，就是假如有个连，[1,2,3]，那么后面可以加上4，所以就建立4的映射。
//这样我们首先遍历一遍数组，统计每个数字出现的频率，然后我们开始遍历数组，
//对于每个遍历到的数字，首先看其当前出现的次数，如果为0，则继续循环；
//如果need中存在这个数字的非0映射，那么表示当前的数字可以加到某个连的末尾，
//我们将当前数字的映射值自减1，然后将下一个连续数字的映射值加1，
//因为当[1,2,3]连上4后变成[1,2,3,4]之后，就可以连上5了；
//如果不能连到其他子序列后面，我们来看其是否可以成为新的子序列的起点，可以通过看后面两个数字的映射值是否大于0，
//都大于0的话，说明可以组成3连儿，于是将后面两个数字的映射值都自减1，还有由于组成了3连儿，
//在need中将末尾的下一位数字的映射值自增1；如果上面情况都不满足，说明该数字是单牌，只能划单儿，
//直接返回false。最后别忘了将当前数字的freq映射值自减1。退出for循环后返回true，


////////////////////////////////////////////////


//刚开始的时候老是想着在扫描数组时，每扫描到一个新的数字都要确定以该数字为开头的一个连续序列。
//其实根本不需要扫到一个数字就确定一个连续序列，而是可以在扫描数组的过程中，把数字逐一地添加到未完整的连续序列中，
//动态地往连续序列中添加数据。整个算法过程如下：
//
//维护两个哈希表 frequency 和 tails. frequency 表记录数组中每个数字出现的次数，而 tails
//表则记录以某个数字结尾的连续序列的个数，比如 tails[key] 的值为2，表示以数字 key 为结尾的连续序列共有两个。
//
//第一次扫描数组，把数组中每个数字的出现次数记录到 frequency 表中。
//
//第二次扫描数组，对扫描到的每一个数字 num，如果 tails[num - 1] > 0 ，
//说明存在以 num - 1 为结尾的连续序列，则把数字 num 添加到该连续序列中：tails[num - 1]--;
//tails[num]++。可能有人会担心 num可能是另一个连续序列的开始数字而不应该加入到 tails[num - 1] 的连续序列中，
//但是任意以 num 为开始数组的连续序列都可以与 tails[num - 1] 的连续序列合并：
//比如 [1, 2, 3] 和 [4, 5, 6] 两个连续序列是可以合并成 [1, 2, 3, 4, 5, 6] 这个大的连续序列的，这对于结果是没有影响的；

//如果 tails[num - 1] == 0 ，此时我们就需要以 num 为开始数字建立一个新的连续序列。而一个连续序列至少包含 3 个数字，
//因此还要检查 num + 1 和 num + 2 这两个数字是否存在，如果不存在，则直接 return false ，
//否则，新建以 num + 2 数字为结尾的连续序列。
//
//如果上述过程能进行到最后，说明所有连续序列都能够找出来，则直接 return true。




