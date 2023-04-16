/**
 * @Classname ${NAME}
 * @Description TODO
 * @Date ${DATE} ${TIME}
 * @Created by ${USER}
 */

package com.huazaiki.leetcode.Double_pointer.Date_4_8;

import java.util.Arrays;
import java.util.HashSet;

/*
    一个朴素的做法是利用「双指针」进行前后扫描，
    当左右指针都是元音字母时，进行互换并移到下一位。

    由于元音字母相对固定，因此我们可以使用容器将其存储，并使用 static 修饰，
    确保整个容器的创建和元音字母的填入在所有测试样例中只会发生一次。

    我们期望该容器能在 O(1) 的复杂度内判断是否为元音字母，
    可以使用语言自带的哈希类容器（P2 代码）或是使用数组模拟（P1 代码）。

    一些细节：由于题目没有说字符串中只包含字母，因此在使用数组模拟哈希表时，
    我们需要用当前字符减去 ASCII 码的最小值（空字符），而不是 'A'
*/
public class Reverse_Vowels_of_a_String_0345 {
    public static void main(String[] args) {

    }
}

class Solution2 {
    private final static HashSet<Character> vowels = new HashSet<>(
            Arrays.asList('a','e','i','o','u','A','E','I','O','U')
    );

    public String reverseVowels(String s) {
        if (s == null) return null;
        int i = 0, j = s.length() - 1;
        char[] result = new char[s.length()];
        while (i <= j) {
            char ci = s.charAt(i);
            char cj = s.charAt(j);
            if(!vowels.contains(ci)) {
                result[i++] = ci;
            } else if (!vowels.contains(cj)) {
                result[j--] = cj;
            } else {
                result[i++] = cj;
                result[j--] = ci;
            }
        }
        return new String(result);
    }
}