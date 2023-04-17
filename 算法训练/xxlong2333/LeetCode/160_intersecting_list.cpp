#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<unordered_set>

/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

图示两个链表在节点 c1 开始相交：


输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
— 请注意相交节点的值不为 1，因为在链表 A 和链表 B 之中值为 1 的节点 (A 中第二个节点和 B 中第三个节点) 是不同的节点。换句话说，它们在内存中指向两个不同的位置，而链表 A 和链表 B 中值为 8 的节点 (A 中第三个节点，B 中第四个节点) 在内存中指向相同的位置。


*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


//方法一: 哈希表
/* 放入哈希表 循环判断是否相等，相等时 返回temp
*/
class Solution{
public:

    ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){
        unordered_set<ListNode *>visted;
        ListNode *temp=headA;
        while(temp!=nullptr){
            visted.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp!=nullptr){
            if(visted.count(temp)){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};
//方法2：双指针

/*
双指针法 m+s+n=n+s+m;
*/

class Solution{
    ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){

        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }

        ListNode *pA=headA;
        ListNode *pB=headB;
        
        while(pA!=pB){
            pA=pA==nullptr?headB:pA->next;
            pB=pB==nullptr?headA:pB->next;
        }
        return pA;
    }
};
int main(){


    return 0;
}