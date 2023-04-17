#include<iostream>
using namespace std;
#include<string>

/*
    给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
    元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
    示例 1：
    输入：s = "hello"
    输出："holle"
    示例 2：
    输入：s = "leetcode"
    输出："leotcede"
     
    提示：
    1 <= s.length <= 3 * 105
    s 由 可打印的 ASCII 字符组成

*/
class Solution{
    public:
        string reverseVowels(string s){
            auto isVowel=[vowels="aeiouAEIOU"s](char ch){
                return vowels.find(ch)!=string::npos;
            };
            int n=s.size();
            int i=0,j=n-1;

            while(i<j){
                while(i<n&&!isVowel(s[i])){
                    ++i;
                }

                while(j>0&&!isVowel(s[j])){
                    --j;
                }

                if(i<j){
                swap(s[i],s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }          
};

int main(){

    Solution s1;
    cout<<s1.reverseVowels("hello")<<endl;
    cout<<s1.reverseVowels("leetcode")<<endl;

   return 0;
}

