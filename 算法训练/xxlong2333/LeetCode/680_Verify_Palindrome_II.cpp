#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

/*
给你一个字符串 s，最多 可以从中删除一个字符。
请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false 。

输入：s = "aba"
输出：true
*/

//方法1：暴力枚举--时间：o(n^2)  空间o(n)

/*
如果起始字符相同，只用判断中间字符是回文串
如果起始字符不同，必须删除其一

算法：
1.初始化两个指针 i j  
2.循环判断 s[i] ...s[j]是否为回文
3.i>=j 结束
4.起始相同 继续比较中间字符 i++ j-- 否则必须删除 s[i]或s[j]
*/

//方法2：贪心算法  时间：o(n)  空间o(1)
class Solution{
    public:
        //判断是否满足回文串
        bool isPalinadromeRange(string s,int i,int j){    

            for(;i<j;i++,j--){
                int n=0;
                if(s[i]!=s[j]){                
                    return false;
                }
                
            }
            return true;
                // //简化代码
                // for(;i<j&&s[i]==s[j];++i,--j){
                // return i>=j;
                // }
                
        }

    bool validPalinadrome(string s){

            int i=0,j=s.size()-1;                       //索引

            for(;s[i]!=s[j]&&i<j;++i,--j){                  //删除左边或右边的字符再判断  左边+1  右边-1

                /*
                    // 至此有两种情况：
                    // ① i>=j s本身就是回文串
                    // ② i<j && s[i] != s[j]必须要删一个
                    //   要么删s[i]，判断s[i+1,j]是否是回文串
                    //   要么删s[j]，判断s[i,j-1]是否是回文串
                */
                return isPalinadromeRange(s,i+1,j)||isPalinadromeRange(s,i,j-1);
            }
            return true;
        }   
};

int main(){

    Solution s1;
    s1.validPalinadrome("abca");
    if (s1.validPalinadrome("abca")) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}