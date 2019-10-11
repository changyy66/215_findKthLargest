// 215_findKthLargest.cpp : 定义控制台应用程序的入口点。
//
/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int quicksort(vector<int>& nums, int k,int start, int end)
	{
		int tmp = nums[start];
		int i = start;
		int j = end;
		while (i<j)
		{
			while (i < j&&nums[j] >= tmp)
			{
				j--;
			}
			nums[i] = nums[j];
			nums[j] = tmp;
			while (i<j&&nums[i]<=tmp)
			{
				i++;
			}
			nums[j] = nums[i];
			nums[i] = tmp;
		}
		if (i <( nums.size() - k))
		{
			return quicksort(nums, k, i + 1, end);
		}
		else if (i>(nums.size()-k))
		{
			return quicksort(nums, k, start, i-1);
		}
		return nums[i];
		
	}

	int findKthLargest(vector<int>& nums, int k) {
		return quicksort(nums, k, 0, nums.size() - 1);
	}
};

int main()
{
    return 0;
}

