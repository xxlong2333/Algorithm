#include<iostream>
using namespace std;

/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
*/

//定义一个链表
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode *next):val(x),next(next){}
};

//迭代  0->1->2->3->4->5     1<-2<-3<-4<-5
class Solution{
    public:
    ListNode *reverseList(ListNode *head){

        ListNode *prev=nullptr;             //上一个节点
        ListNode *curr=head;

        while(curr!=nullptr){

             ListNode *next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
        }
        return prev;
    }
};

// // 单链表节点定义
// class ListNode {
// public:
//     int val;
//     ListNode* next;
//     ListNode(int val) {
//         this->val = val;
//         this->next = nullptr;
//     }
// };

// 反转链表并返回反转后的链表的头节点
ListNode* reverseList(ListNode* head) {
    ListNode* current_node = head;
    ListNode* prev_node = nullptr;
    while (current_node != nullptr) {
        ListNode* next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    return prev_node;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current_node = head;
    while (current_node != nullptr) {
        cout << current_node->val << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    cout << "Original List: ";
    printList(head);
    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);
    return 0;
}