package com.huazaiki.leetcode.Double_pointer.Date_4_15;

import java.util.Arrays;

/**
 * @Description TODO
 * @Date 2023/4/15 17:23
 * @Author by huazaiki
 */

public class Merge_Sorted_Array_88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index1 = m - 1, index2 = n - 1; //index1 就是 nums1的右指针
                                            //相同的，index2 就是 nums2的右指针
        int indexMerged = m + n - 1;    //indexMerged 就是 最终数组的的右指针（作用不同于index1)
        while (index2 >= 0) {
            if (index1 < 0) {
                nums1[indexMerged--] = nums2[index2--];
                //这里就是判断 如果 nums1的右指针到头了 也就是nums1里面没有数字需要遍历了
                //我们就让 nums2里面右指针所指的数字赋值到 目标数组indexMerged所指的位置
                //然后 indexMerged 指针和 index2 指针同时左移一位
            } else if (index2 < 0) {
                nums1[indexMerged--] = nums1[index1--];
            } else if (nums1[index1] > nums2[index2]) {
                //这里是题意中排序的部分
                //如果本数组中的右指针所指的数字大于nums2数组中右指针所指的数字
                //那么就让我本数组中的数字来填补
                //反之就让你来填补
                nums1[indexMerged--] = nums1[index1--];
            } else {
                nums1[indexMerged--] = nums2[index2--];
            }
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1,2,3,0,0,0};
        int[] nums2 = {2,5,6};
        new Solution1().merge(nums1, 3, nums2, 3);
        System.out.println("");
        for (int i = 0; i < nums1.length; i++) {
            System.out.print(nums1[i] + " ");
        }
    }
}

//我想到的解法，有点刁钻了哈哈哈
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[m+i] = nums2[i];
        }
        Arrays.sort(nums1);
    }
}

//同样的思路不同的写法
class Solution1 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int indexM = m - 1;
        int indexN = n - 1;
        int indexSum = m + n - 1;
        while (indexM >= 0 && indexN >= 0) {
            nums1[indexSum--] = nums1[indexM] > nums2[indexN] ? nums1[indexM--] : nums2[indexN--];
        }
        /*
        for (int i = 0; i < nums1.length; i++) {
            System.out.print(nums1[i] + " ");
        }
        */
        System.arraycopy(nums2, 0, nums1, 0, indexN + 1);
    }
}
