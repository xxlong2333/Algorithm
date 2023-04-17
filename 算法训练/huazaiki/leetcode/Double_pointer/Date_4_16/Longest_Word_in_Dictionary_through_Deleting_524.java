package com.huazaiki.leetcode.Double_pointer.Date_4_16;

import java.util.List;

/**
 * @Description TODO
 * @Date 2023/4/16 17:59
 * @Author by huazaiki
 */

public class Longest_Word_in_Dictionary_through_Deleting_524 {
    private boolean isSubstr(String s, String target) {
        //定义两个左指针 i 和 j
        int i = 0, j = 0;
        while (i < s.length() && j < target.length()) {
            //当两个指针都还能继续右移
            if (s.charAt(i) == target.charAt(j)) {
                //如果匹配上了就让遍历字符串指针右移，这样做的目的是为了找到我们要找的遍历字符串的第一个字符
                //这一步可以来讨论一下，我也是看了好几遍才看懂
                j++;
            }
            //找到之后就右移给定字符串的指针，继续对比下一个
            i++;
        }
        //遍历完了之后就可以比较长度了，倘若两个长度也相同那就返回true表示找到了！
        return j == target.length();
    }

    public String findLongestWord(String s, List<String> d) {
        // d是字符串数组
        String longestWord = "";
        for (String target : d) {   //遍历 d中的各个字符串
            int l1 = longestWord.length(), l2 = target.length();
            if (l1 > l2 || (l1 == l2 && longestWord.compareTo(target) < 0)) {
                //开始比较 遍历字符串 和 现在最长的字符串长度
                //如果最长的比遍历的字符串大 或者 两个字符串长度相同 但是遍历字符串中的个字符大小不比最长字符串小
                //就退出循环
                continue;
            }
            if (isSubstr(s, target)) {
                //调用 isSubstr() 给定题中字符串和遍历字符串
                //如果返回了true 那么我们就找到了一个与当前遍历字符串相匹配的字符段
                longestWord = target;
            }
        }
        return longestWord;
    }
}

class Solution {
    private boolean isSubstr(String s, String target) {
        int i = 0, j = 0;
        while (i < s.length() && j < target.length()) {
            if (s.charAt(i) == target.charAt(j)) {
                j++;
            }
            i++;
        }
        return j == target.length();
    }

    public String findLongestWord(String s, List<String> d) {
        String longestWord = "";
        for (String target : d) {
            int l1 = longestWord.length(), l2 = target.length();
            if (l1 > l2 || (l1 == l2 && longestWord.compareTo(target) < 0)) {
                continue;
            }
            if (isSubstr(s, target)) {
                longestWord = target;
            }
        }
        return longestWord;
    }

}

