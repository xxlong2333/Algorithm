package com.huazaiki.leetcode.Double_pointer.Date_4_15;

/**
 * @Description TODO
 * @Date 2023/4/9 2:06
 * @Auther by huazaiki
 */

/*
    回文字符串 -- 680. Valid Palindrome II (Easy)

    题目描述：可以删除一个字符，判断是否能构成回文字符串。

    所谓的回文字符串，是指具有左右对称特点的字符串，例如 "abcba" 就是一个回文字符串。

    使用双指针可以很容易判断一个字符串是否是回文字符串：令一个指针从左到右遍历，一个
    指针从右到左遍历，这两个指针同时移动一个位置，每次都判断两个指针指向的字符是否相同，
    如果都相同，字符串才是具有左右对称性质的回文字符串。

    本题的关键是处理删除一个字符。在使用双指针遍历字符串时，如果出现两个指针指向的字符不相等的情况，
    我们就试着删除一个字符，再判断删除完之后的字符串是否是回文字符串。

    在判断是否为回文字符串时，我们不需要判断整个字符串，因为左指针左边和右指针右边的字符之前已经判断过具有对称性质，
    所以只需要判断中间的子字符串即可。

    在试着删除字符时，我们既可以删除左指针指向的字符，也可以删除右指针指向的字符。
*/

public class Valid_Palindrome_680 {

    public boolean validPalindrome(String s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                //这里比较 i 指针和 j 指针的值
                //如果值不相同就让他们的左指针加一或者右指针减一 以达到删除一个元素的目的
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
                //isPalindrome(s, i, j - 1) 就是将以一个新数组的视角来判断了
            }
        }
        return true;
    }

    private boolean isPalindrome(String s, int i, int j) {
        // i j 左右指针
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                //如果 i 指针所指的元素 = j 指针所知的元素
                // i++ j-- 左右指针往中间各移一位
                //如果不相同，if判断体里面的值就为true 则进入下面 return false
                return false;
            }
        }
        //如果 i 指针不在 j指针左边了就退出循环
        //那么就证明 这个字符串是正确的回文串 继而return true
        return true;
    }

    public static void main(String[] args) {
        String s = "acbaaa";
        System.out.println(new Valid_Palindrome_680().validPalindrome(s));
    }
}
