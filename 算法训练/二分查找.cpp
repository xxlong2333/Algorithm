#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();	// ����target������ҿ������������[left, right)
		while (left < right) {
			int middle = left + ((right - left) >> 1);	// ��Ϊleft == right��ʱ����[left, right)����Ч�Ŀռ䣬����ʹ�� <
			if (nums[middle] > target) {
				right = middle;		// target �������䣬��[left, middle)��
			}
			else if (nums[middle] < target) {
				left = middle + 1;	// target �������䣬��[middle + 1, right)��
			}
			else {	// nums[middle] == target
				return middle;	// �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		// δ�ҵ�Ŀ��ֵ
		return -1;
	}
};

class Solution2 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1; // ����target������ұյ������[left, right]
		while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч�������� <=
			int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
			if (nums[middle] > target) {
				right = middle - 1; // target �������䣬����[left, middle - 1]
			}
			else if (nums[middle] < target) {
				left = middle + 1; // target �������䣬����[middle + 1, right]
			}
			else { // nums[middle] == target
				return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		// δ�ҵ�Ŀ��ֵ
		return -1;
	}
};
