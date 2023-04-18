#include<iostream>
using namespace std;


class ListNode{
public:
    ListNode *next;
    int val;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode*next):val(x),next(nullptr){};

};
//1.暴力解法  o(n+m)  o(1)
//哑节点
class Solution{
    public:
        ListNode *mergeTwoList(ListNode* L1,ListNode* L2){

            ListNode* prev=new ListNode(-1);
            ListNode* prevHead=prev;

            while(L1!=nullptr&&L2!=nullptr){
                if(L1->val<L2->val){
                    prev->next=L1;
                    L1=L1->next;
                }else{
                    prev->next=L2;
                    L2=L2->next;
                }
                prev=prev->next;
            }
            prev->next=L1==nullptr?L2:L1;
            return prevHead;
        }
};

//方法2：递归
/*
假设 l2 小   合并(L1,L2)等价于L1->next=合并(L1->next,L2)
子问题和原问题具有相同结构，
返回值和要解决的问题都一致

*/
class Solution2{
    public:

};

ListNode *mergeTwoList(ListNode*L1,ListNode*L2){
            
            if(L1==nullptr){
                return L2;
            }else if(L2==nullptr){
                return L1;
            }else if(L1->val<L2->val){
                L1->next=mergeTwoList(L1->next,L2);
                return L1;
            }else{
                L2->next=mergeTwoList(L2->next,L1);
                return L2;
            }

        }

void printList(ListNode* L){

    ListNode* current_node=L;
    while(current_node!=nullptr){
        cout<<current_node->val<<" ";
        current_node=current_node->next;
    }

    cout<<endl;
}

int main(){

    ListNode* L1=new ListNode(1);
    L1->next=new ListNode(2);
    L1->next->next=new ListNode(3);

    ListNode* L2=new ListNode(2);
    L2->next=new ListNode(3);
    L2->next->next=new ListNode(5);

    cout<<"未合并前："<<endl;
    printList(L1);
    printList(L2);


    ListNode* L3=mergeTwoList(L1,L2);

    printList(L3);
    return 0;
}
