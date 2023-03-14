#include <iostream>
#include <vector>
using namespace std;

// �����ⷨ
// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // ������Ҫ�Ƴ���Ԫ�أ��ͽ����鼯����ǰ�ƶ�һλ
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // ��Ϊ�±�i�Ժ����ֵ����ǰ�ƶ���һλ������iҲ��ǰ�ƶ�һλ
                size--; // ��ʱ����Ĵ�С-1
            }
        }
        return size;
    }
};

// ˫ָ�뷨������ָ�뷨��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

/**
* ����˫ָ�뷽��������Ԫ��˳����Ըı����Ŀ�����ı���Ԫ�����λ�ã�ȷ�����ƶ�����Ԫ��
* ʱ�临�Ӷȣ�O(n)
* �ռ临�Ӷȣ�O(1)
*/
class Solution3 {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // ����ߵ���val��Ԫ��
            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
                ++leftIndex;
            }
            // ���ұ߲�����val��Ԫ��
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                --rightIndex;
            }
            // ���ұ߲�����val��Ԫ�ظ�����ߵ���val��Ԫ��
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndexһ��ָ������������ĩβ����һ��Ԫ��
    }
};