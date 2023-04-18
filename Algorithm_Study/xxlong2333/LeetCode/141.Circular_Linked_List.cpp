#include<iostream>
using namespace std;
#include<unordered_set>

/*
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。

*/

//1.普通解法  哈希表 时间o(n) 空间o(n)

//2.快慢指针法   时间o(n) 空间o(1)   
/*
慢指针每次访问一次，快指针访问两次，快指针比慢指针快一个即可
当无环时快指针速度快 提前结束，如果有环  快慢指针最后会重合 
*/

//单链表
class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(NULL){ }
};

//1.哈希表 unordered_set 容器 

//时间 o(n) 最坏的情况  遍历每个节点一次
//空间 o(n) 最坏的情况，插入每一个节点一次到哈希表
class Solution{
    public:
        bool hasCycle(ListNode *head){
            unordered_set<ListNode*>seen;
            if(head!=NULL){
                return true;
            }else{
                seen.insert(head);
                head=head->next;
               
            }
             return false;
        }   
};

//2.快慢指针法
class Solution2{
    public:
};

bool hasCycle(ListNode *head){


            if(head==nullptr||head->next==nullptr){
                return false;
            }

            ListNode* fast=head->next;             
            ListNode* slow=head;      

            while(fast!=slow){
                if(fast==nullptr||fast->next==nullptr){           //快指针为空指针
                    return false;
                }
                slow=slow->next;
                fast=fast->next->next;     
            }   
        return true;
     }
int main() {

    // 测试用例1：包含环
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    head->next->next->next->next = head->next;  // 形成环

    if (hasCycle(head))
        cout << "linkedlist has cycle." << endl;
    else
        cout << "linkedlist doesn't have cycle." << endl;
    
    // 测试用例2：不包含环
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    
    if (hasCycle(head2))
        cout << "linkedlist has cycle." << endl;
    else
        cout << "linkedlist doesn't have cycle." << endl;
    return 0;
}