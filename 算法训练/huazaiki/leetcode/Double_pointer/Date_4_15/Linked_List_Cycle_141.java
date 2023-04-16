package com.huazaiki.leetcode.Double_pointer.Date_4_15;

/**
 * @Description TODO
 * @Date 2023/4/15 18:02
 * @Author by huazaiki
 */

/* 双指针并不是固定的公式，而是一种思维方式！！！
 * 快慢指针的特性 —— 每轮移动之后两者的距离会加一。
 * 当一个链表有环时，快慢指针都会陷入环中进行无限次移动，然后变成了追及问题。
 * 想象一下在操场跑步的场景，只要一直跑下去，快的总会追上慢的。
 * 当两个指针都进入环后，每轮移动使得慢指针到快指针的距离增加一，
 * 同时快指针到慢指针的距离也减少一，只要一直移动下去，快指针总会追上慢指针。
 * 这里既涉及到了双指针，又涉及到了链表的相关知识
 * */

public class Linked_List_Cycle_141 {
    //如果一个链表存在环，那么快慢指针必然会相遇。
    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }
        ListNode l1 = head, l2 = head.next; //定义一个快指针 l2, 慢指针 l1
        while (l1 != null && l2 != null && l2.next != null) {
            if (l1 == l2) { //这就是关键，这里判断的意思是，快指针是否追上了慢指针，如果追上了就返回true
                return true;
            }
            l1 = l1.next;
            l2 = l2.next.next;
        }
        return false;
    }
}
//  Definition for singly-linked list. 定义单链表
class ListNode {
  int val;
  ListNode next;
  ListNode(int x) {
      val = x;
      next = null;
  }
}
