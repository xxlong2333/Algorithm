#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"


*/

class Solution{

public:

    //判断t 是否是 s 的字串
    bool isSubsequence(string s,string t){



        //str s

        // int i=0,j=0;
        // while(i<s.size()&&j<t.size()){

        //     if(s[i]==t[j]){                 //字符匹配
        //         i++;
        //     }    
        //     j++;
        // }        
        // return i==s.size();
        


        int n=s.size();
        int m=t.size();

        if(m>n) return false;

        int i=0;
        for(char ch:t){
            while(i<n&&s[i]!=ch) i++;
            if(i>=n)    return false;
            i++;
        }
        return true;
    }


    string findLongestWord(string s,vector<string>&dictionary){
        
        //
        sort(dictionary.begin(),dictionary.end(),[](const string &a,const string &b){
            return a.size()==b.size()? a<b:a.size()>b.size();
        });


        for(string& str:dictionary){
            if(isSubsequence(s,str)){
                return str;
            }
        }

        //没有找到
        return "";
    }   
};



bool issubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.size();
}

string findlongestword(string s, vector<string>& dictionary) {

    sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b){
        return a.size() == b.size() ? a < b : a.size() > b.size();          //lambda表达式定义了一个比较函数
    });                               //该函数首先比较字符串长度，如果长度相等则按照字典序排序；否则按照字符串长度从大到小排序。
                                    //将字典按照字符串长度从大到小排序，并且在长度相等的情况下按照字典序排序。

    for (auto& str : dictionary) {              //auto被声明为一个迭代变量,其类型会根据dictionary容器元素的类型被自动推导出来
        if (issubsequence(str, s)) {
            return str;
        }
    }
    return "";
}

int main()
{
    string s = "abpcplea";
    vector<string> dictionary = {"ale","apple","monkey","plea"};

    cout << findlongestword(s, dictionary) << endl;

    return 0;
}