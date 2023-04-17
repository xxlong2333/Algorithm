#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*  合并有序数组--88
    给定两个有序数组 nums1-m   nums2-n 合并nums2到nums1同样按照非递减顺序排序


    输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    输出：[1,2,2,3,5,6]
    解释：需要合并 [1,2,3] 和 [2,5,6] 。
    合并结果是 [1,2,2,3,5,6]
    

*/

//方法一：合并后排序 时间 o((n+m)xlog(n+m)) 空间o(1)

//方法二：双指针 从前往后  时间 o(n+m) 空间o(m):数组进行拷贝

//方法三：从后往前  o(n+m):对两个数组分别遍历  o(1)


//合并后再排序
class Solution1{
    public:

        void merge(vector<int>&nums1,int m,vector<int>&nums2,int n){
            for(int i=0;i!=n;i++){
                nums1[m+i]=nums2[i];
            }

           sort(nums1.begin(),nums1.end());
        }
};

//双指针法--正向
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged(m + n);          //新建数组  长度为m+n 
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        while (i < m) {
            merged[k++] = nums1[i++];
        }
        while (j < n) {
            merged[k++] = nums2[j++];
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = merged[i];
        }
    }
};



//双指针法--逆向
class Solution3{
 public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1, j = n - 1, k = m + n - 1; // i、j、k 分别表示 nums1、nums2 和合并后数组的索引

        while (i >= 0 && j >= 0) { // 比较 nums1 和 nums2 中元素大小，并按照从大到小的顺序将较大的放入合并后数组中
            if (nums1[i] > nums2[j]) {      //找出大的
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];  
            }
        }

        
        while (j >= 0) { // 将剩余的 num2 元素依次放入合并后数组的前面  有序数组剩下的都是前面小的数
            nums1[k--] = nums2[j--];
        }

    
    }
};

int main(){

    Solution2 s1;

    vector<int>nums1={1,2,3,4,0,0,0};
    int m=4;            //m n 表示nums1 nums2 元素的个数   此时用 nums1.size()错误

    vector<int>nums2={2,5,6};
    int n=3;

    s1.merge(nums1,m,nums2,n);

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }                           // 1 2 2 3 4 6

    cout<<endl;
    return 0;
}